#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Get stylesheet info object
    ss = new IllusionSS();
    //Color all labels brown
    this->setStyleSheet(ss->labelColor);

    //Idle screen timer
    interactionTimer = new QTimer(this);
    connect(interactionTimer, SIGNAL(timeout()), this, SLOT(switchToIdleScreen()));
    interactionTimer->start(idleWaitSeconds * 1000);

    //Top-level layered widget
    topStackedWidget = new QStackedWidget(this);

    //Top-level exhibit widget
    exhibitWidget = new QWidget();

    //Create layout and set margins
    exhibitVLayout = new QVBoxLayout(exhibitWidget);
    exhibitVLayout->setContentsMargins(ss->exhibitMargins);
    //Instantiate opacity for exhibit widget
    exhibitOpacity = new QGraphicsOpacityEffect(this);
    exhibitWidget->setGraphicsEffect(exhibitOpacity);
    exhibitOpacity->setOpacity(1);

    //Font initialization
    QFont titleFont = ss->ChaletBook_Bold;

    //Create and add title widget
    title = new QLabel("Illusions");
    titleFont.setBold(true);
    titleFont.setPixelSize(120);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignLeft);
    exhibitVLayout->addWidget(title);

    //Illusion widget and buttons navigation list
    illusionStackedWidget = new QStackedWidget(exhibitWidget);
    opticalButtonsList = new QList<WidgetButton*>();
    audioButtonsList = new QList<WidgetButton*>();

    //Initialize and populate file path maps from illusion to text description
    importIllusions();

    //Create text explanation widget
    illusionExplanationText = new HiddenTextWidget("", "");
    connect(illusionExplanationText, SIGNAL(textRevealed()), this, SLOT(restartInteractionTimer()));

    //Import optical and audio illusions
    audioIllusionWidget = createAudioWidget();
    illusionStackedWidget->addWidget(audioIllusionWidget);
    exhibitVLayout->addWidget(illusionStackedWidget);

    //Add text explanation to layout
    illusionExplanationText->setFixedHeight(400);
    exhibitVLayout->addWidget(illusionExplanationText);

    //Illusion select widget
    QWidget* menuWidget = createMenuWidget();
    illusionSelectWidget->setCurrentIndex(0);
    exhibitVLayout->addWidget(menuWidget);
    exhibitVLayout->addSpacing(300);

    //Idle screen widget
    idleWidget = createIdleScreenWidget();
    //instantiate opacity for idle screen
    idleOpacity = new QGraphicsOpacityEffect(this);
    idleWidget->setGraphicsEffect(idleOpacity);
    idleOpacity->setOpacity(0);

    //Add background image
    QPalette backgroundImage = ss->backgroundImage();
    this->setPalette(backgroundImage);

    //Add all created widgets to top-level stacked widget and set central widget
    topStackedWidget->addWidget(exhibitWidget);
    topStackedWidget->addWidget(idleWidget);
    topStackedWidget->setCurrentWidget(exhibitWidget);
    this->setCentralWidget(topStackedWidget);

    //Select first illusion
    activeButton = opticalButtonsList->first();
    opticalButtonsList->first()->click();

    //set first frame sequence/video tracker playthrough tracker
    isFirstPlayAudio = false;

    restartInteractionTimer();
}

void MainWindow::importIllusions() {
    //Instantiate maps
    opticalFileMap = new QMap<QWidget*, QString>();
    audioFileMap = new QMap<QString, QString>();

    //Import optical illusions
    if(!QDir(opticalFilePath).isEmpty()) {
        QDirIterator opticalFileIterator(opticalFilePath, QDir::AllEntries | QDir::NoDotAndDotDot);
        while(opticalFileIterator.hasNext()) {
            QFileInfoList illusionFile = QDir(opticalFileIterator.filePath()).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
            QString illusionPath = "";
            QString textPath = "";
            for(QFileInfo file : illusionFile) {
                if(file.isDir() || QImageReader::imageFormat(file.absoluteFilePath()) != "" || ss->videoFileSuffixes.contains(file.suffix())) {
                    illusionPath = file.absoluteFilePath();
                } else if(file.suffix() == "txt") {
                    textPath = file.absoluteFilePath();
                }
                if(!illusionPath.isEmpty() && !textPath.isEmpty()) {
                    QWidget *illusion = createOpticalWidget(illusionPath);
                    QString iconPath = opticalButtonIconsPath + QFileInfo(illusionPath).baseName() + ".jpg";
                    WidgetButton *button = new WidgetButton(illusion, iconPath);
                    button->setIconSize(ss->illusionButtonSize);
                    button->setMaximumSize(ss->illusionButtonSize);
                    opticalButtonsList->push_front(button);
                    illusionStackedWidget->addWidget(illusion);
                    connect(button, SIGNAL(buttonClicked(QWidget*)), this, SLOT(changeOpticalIllusion(QWidget*)));

                    opticalFileMap->insert(illusion, textPath);
                    break;
                }
            }
            opticalFileIterator.next();
        }
    } else {
        QMessageBox::warning(0, ss->warningTitle, ss->getEmptyFileMessage(opticalFilePath));
    }

    if(!QDir(audioFilePath).isEmpty()) {
        QDirIterator audioFileIterator(audioFilePath);
        while(audioFileIterator.hasNext()) {
            QFileInfoList illusionFile = QDir(audioFileIterator.filePath()).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
            QString illusionPath = "";
            QString textPath = "";
            for(QFileInfo file : illusionFile) {
                if(ss->audioFileSuffixes.contains(file.suffix())) {
                    illusionPath = file.absoluteFilePath();
                } else if(file.suffix() == "txt") {
                    textPath = file.absoluteFilePath();
                }
                if(!illusionPath.isEmpty() && !textPath.isEmpty()) {
                    audioFileMap->insert(illusionPath, textPath);

                    QLabel *illusion = new QLabel(illusionPath);
                    QString iconPath = audioButtonIconsPath + QFileInfo(illusionPath).baseName() + ".jpg";
                    WidgetButton *button = new WidgetButton(illusion, iconPath);
                    button->setIconSize(ss->illusionButtonSize);
                    button->setMaximumSize(ss->illusionButtonSize);
                    audioButtonsList->push_front(button);
                    connect(button, SIGNAL(buttonClicked(QWidget*)), this, SLOT(changeAudioIllusion(QWidget*)));
                    break;
                }
            }
            audioFileIterator.next();
        }
    } else {
        QMessageBox::warning(0, ss->warningTitle, ss->getEmptyFileMessage(opticalFilePath));
    }
}

QWidget* MainWindow::createOpticalWidget(QString filePath) {
    QWidget *illusionWidget = new QWidget(this);
    QVBoxLayout *illusionLayout = new QVBoxLayout(illusionWidget);

    //Title of illusion
    opticalIllusionLabel = new QLabel(illusionWidget);
    opticalIllusionLabel->setText(QFileInfo(filePath).baseName());
    QFont chaletBookOblique = ss->ChaletBook_Oblique;
    chaletBookOblique.setPixelSize(40);
    opticalIllusionLabel->setFont(chaletBookOblique);
    opticalIllusionLabel->setAlignment(Qt::AlignLeft);
    illusionLayout->addWidget(opticalIllusionLabel);

    if(QFileInfo(filePath).isFile() && !QImageReader::imageFormat(filePath).isNull()) { //File is single image
        //Create illusion icon and add to layout
        QLabel *illusion = new QLabel(illusionWidget);
        QPixmap *illusionIcon = new QPixmap();
        illusionIcon->load(filePath);
        *illusionIcon = illusionIcon->scaledToWidth(qApp->screens()[0]->size().width() - 200);
        illusion->setAlignment(Qt::AlignCenter);
        illusion->setPixmap(*illusionIcon);

        //Sizing and spacing
        QWidget* spacedIllusion = getSpacedIllusion(illusion);
        spacedIllusion->setParent(illusionWidget);
        illusionLayout->addWidget(spacedIllusion);
    } else if(QFileInfo(filePath).isDir()){ //File is folder, so illusion is frame sequence
        QList<QImage> *frameList = loadFrameSequence(filePath);
        FrameSequenceWidget *frameSeq = new FrameSequenceWidget(frameList, ss->defaultInterval, this);
        connect(frameSeq, SIGNAL(firstSequenceStarted()), this, SLOT(pauseInteractionTimer()));
        connect(frameSeq, SIGNAL(firstSequenceFinished()), this, SLOT(restartInteractionTimer()));
        connect(illusionStackedWidget, SIGNAL(currentChanged(int)), frameSeq, SLOT(restartSequence(int)));
        connect(illusionStackedWidget, SIGNAL(currentChanged(int)), frameSeq, SLOT(resetIsFirstPlay(int)));
        connect(this, SIGNAL(switchedToExhibitScreen(int)), frameSeq, SLOT(resetIsFirstPlay(int)));

        //Sizing and spacing
        QWidget* spacedIllusion = getSpacedIllusion(frameSeq);
        spacedIllusion->setParent(illusionWidget);
        illusionLayout->addWidget(spacedIllusion);
    } else { //File is video
        VideoWidget *videoWidget = new VideoWidget(filePath, this);
        connect(videoWidget, SIGNAL(firstVideoStarted()), this, SLOT(pauseInteractionTimer()));
        connect(videoWidget, SIGNAL(firstVideoFinished()), this, SLOT(restartInteractionTimer()));
        connect(illusionStackedWidget, SIGNAL(currentChanged(int)), videoWidget, SLOT(resetAndPause(int)));
        connect(this, SIGNAL(switchedToExhibitScreen(int)), videoWidget, SLOT(resetAndPlay(int)));
        connect(this, SIGNAL(switchedActiveIllusion(QWidget*)), videoWidget, SLOT(updateActiveWidget(QWidget*)));

        //Sizing and spacing
        QWidget* spacedIllusion = getSpacedIllusion(videoWidget);
        spacedIllusion->setParent(illusionWidget);
        illusionLayout->addWidget(spacedIllusion);
    }

    return illusionWidget;
}

QWidget* MainWindow::createAudioWidget() {
    QWidget *audioIllusionWidget = new QWidget(this);
    QVBoxLayout *audioIllusionLayout = new QVBoxLayout(audioIllusionWidget);

    audioMediaPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;

    //Audio setup
    audioMediaPlayer->setAudioOutput(audioOutput);
    connect(audioMediaPlayer, SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)), this, SLOT(onPlaybackStateChanged(QMediaPlayer::PlaybackState)));
    connect(audioMediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(onMediaStatusChanged(QMediaPlayer::MediaStatus)));

    //Title of illusion
    audioIllusionLabel = new QLabel(audioIllusionWidget);
    QFont chaletBookOblique = ss->ChaletBook_Oblique;
    chaletBookOblique.setPixelSize(40);
    audioIllusionLabel->setFont(chaletBookOblique);
    audioIllusionLabel->setAlignment(Qt::AlignLeft);
    audioIllusionLayout->addWidget(audioIllusionLabel);

    //Secondary layout excluding title
    QWidget *secondAudioWidget = new QWidget(audioIllusionWidget);
    QVBoxLayout *secondAudioLayout = new QVBoxLayout(secondAudioWidget);
    secondAudioLayout->setAlignment(Qt::AlignHCenter);

    //Soundwave Visualizer
    visualizer = new FrameSequenceWidget(ss->getSoundwaveSeq(), ss->visualizerInterval, this);
    secondAudioLayout->addSpacing(125);
    secondAudioLayout->addWidget(visualizer);
    visualizer->playSequence();
    secondAudioLayout->addSpacing(100);

    //Progress Bar
    audioProgressBar = new QProgressBar;
    audioProgressBar->setTextVisible(false);
    //audioProgressBar->setMinimumHeight(300);
    audioProgressBar->setStyleSheet(ss->audioProgressBarStyle);
    connect(audioMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(setProgressBarPosition(qint64)));
    secondAudioLayout->addWidget(audioProgressBar);
    secondAudioLayout->addSpacing(25);

    //Restart button font setup
    QFont restartFont = ss->ChaletBook_Oblique;
    restartFont.setPointSize(30);

    //Create restart audio button
    audioRestartButton = new QPushButton("Touch to Restart");
    audioRestartButton->setFont(restartFont);

    connect(audioRestartButton, SIGNAL(clicked()), this, SLOT(restartAudio()));
    secondAudioLayout->addWidget(audioRestartButton);

    //Set spacing and style
    secondAudioWidget->setStyleSheet(ss->audioWidgetStyle);

    //Combine layouts
    audioIllusionLayout->addWidget(getSpacedIllusion(secondAudioWidget));

    return audioIllusionWidget;
}

QWidget* MainWindow::getSpacedIllusion(QWidget *illusion) {
    illusion->setFixedSize(ss->illusionSize);
    QWidget *spacingWidget = new QWidget();
    QHBoxLayout *spacingLayout = new QHBoxLayout(spacingWidget);
    spacingLayout->addSpacing(ss->illusionSideMargin);
    spacingLayout->addWidget(illusion);
    spacingLayout->addSpacing(ss->illusionSideMargin);
    return spacingWidget;
}

QString MainWindow::readFirstLine(QString filePath) {
    QString totalText = "";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(0, file.errorString(), "error reading text file " + filePath);
    }
    QTextStream in(&file);
    //Read only first line
    totalText.append(in.readLine());
    file.close();
    return totalText;
}

QString MainWindow::readTextExcludingFirstLine(QString filePath) {
    QString totalText = "";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(0, file.errorString(), "error reading text file " + filePath);
    }
    QTextStream in(&file);
    //Discard first line
    in.readLine();
    //read rest of text
    while(!in.atEnd()) {
        totalText.append(in.readLine());
    }
    file.close();
    return totalText;
}

QList<QImage>* MainWindow::loadFrameSequence(QString filePath) {
    QFileInfoList frameSeqFiles = QDir(filePath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    QList<QImage> *frameList = new QList<QImage>();

    for(QFileInfo frame : frameSeqFiles) {
        frameList->insert(frameList->end(), QImage(frame.absoluteFilePath()));
    }

    return frameList;
}

QWidget* MainWindow::createIllusionTypeButtons() {
    QWidget* illusionTypeSelection = new QWidget(this);

    //Create and connect audio menu button
    audioMenuButton = new QPushButton();
    audioMenuButton->setIcon(QIcon(ss->audioMenuButtonIcons[1]));
    audioMenuButton->setIconSize(ss->illusionTypeButtonSize);
    audioMenuButton->setMaximumWidth(255);
    connect(audioMenuButton, SIGNAL(clicked()), this, SLOT(switchToAudioMenu()));

    //Create and connect optical menu button
    opticalMenuButton = new QPushButton();
    opticalMenuButton->setIcon(QIcon(ss->opticalMenuButtonIcons[0]));
    opticalMenuButton->setIconSize(ss->illusionTypeButtonSize);
    opticalMenuButton->setMaximumWidth(255);
    connect(opticalMenuButton, SIGNAL(clicked()), this, SLOT(switchToOpticalMenu()));

    //Create layout and add buttons
    QVBoxLayout *layout = new QVBoxLayout(illusionTypeSelection);
    layout->addWidget(opticalMenuButton);
    layout->addSpacing(26);
    layout->addWidget(audioMenuButton);
    illusionTypeSelection->setMaximumHeight(200);

    return illusionTypeSelection;
}

QWidget* MainWindow::createMenuWidget() {
    //Top-level menu widget
    QWidget *topMenuWidget = new QWidget(this);

    //Create stacked widget to switch between audio and optical illusions
    QStackedWidget *illusionSelectWidget = new QStackedWidget(topMenuWidget);
    illusionSelectWidget->setParent(topMenuWidget);

    //Instantiate optical and audio menu widgets
    QWidget *opticalSelectWidget = new QWidget();
    QWidget *audioSelectWidget = new QWidget();

    //For each optical illusion, add button to layout
    QHBoxLayout *opticalSelectLayout = new QHBoxLayout(opticalSelectWidget);
    for(int i = 0; i < opticalButtonsList->count(); i++) {
        WidgetButton* button = opticalButtonsList->at(i);
        opticalSelectLayout->addWidget(button);
    }
    illusionSelectWidget->addWidget(opticalSelectWidget);

    //For each audio illusion, add button to layout
    QHBoxLayout *audioSelectLayout = new QHBoxLayout(audioSelectWidget);
    for(int i = 0; i < audioButtonsList->count(); i++) {
        WidgetButton* button = audioButtonsList->at(i);
        audioSelectLayout->addWidget(button);
    }
    illusionSelectWidget->addWidget(audioSelectWidget);
    illusionSelectWidget->setStyleSheet(ss->illusionSelectStyle);

    //QScrollArea setup
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(illusionSelectWidget);

    // hide scrollbars
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Set style and dimensions
    scrollArea->setStyleSheet(ss->scrollAreaStyle);
    //scrollArea->setMaximumHeight(200);
    // configure gesture and add rubberband effect
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    //Create layout to hold menu for switching between illusions AND for switching between types of illusions
    QHBoxLayout *topMenuLayout = new QHBoxLayout(topMenuWidget);

    QToolButton *backButton = new QToolButton();
    backButton->setIcon(QIcon(ss->backButtonPath));
    backButton->setStyleSheet("");
    backButton->setStyleSheet(ss->menuScrollButtonStyle);
    backButton->setIconSize(ss->menuBackForwardButtonSize);
    connect(backButton, SIGNAL(clicked(bool)), this, SLOT(prevIllusionSlot()));
    topMenuLayout->addWidget(backButton);

    topMenuLayout->addWidget(scrollArea);

    QToolButton *forwardButton = new QToolButton();
    forwardButton->setIcon(QIcon(ss->forwardButtonPath));
    forwardButton->setStyleSheet("");
    forwardButton->setStyleSheet(ss->menuScrollButtonStyle);
    forwardButton->setIconSize(ss->menuBackForwardButtonSize);
    connect(forwardButton, SIGNAL(clicked(bool)), this, SLOT(nextIllusionSlot()));
    topMenuLayout->addWidget(forwardButton);

    topMenuLayout->addWidget(createIllusionTypeButtons());

    //Set illusionSelectWidget to be able to switch between menus
    this->illusionSelectWidget = illusionSelectWidget;

    return topMenuWidget;
}

ClickableWidget* MainWindow::createIdleScreenWidget() {
    ClickableWidget *idleWidget = new ClickableWidget();
    QVBoxLayout *idleLayout = new QVBoxLayout((QWidget*)idleWidget);
    idleLayout->setContentsMargins(ss->idleMargins);
    QLabel *idlePicture = new QLabel();
    QPixmap illusionIcon;
    QRect dimensions(0, 0, 1080, 1970);
    illusionIcon.load(ss->idlePath);
    idlePicture->setPixmap(illusionIcon.copy(dimensions));

    idleLayout->addWidget(idlePicture);
    connect(idleWidget, SIGNAL(clicked()), this, SLOT(switchToExhibitScreen()));

    return idleWidget;
}

void MainWindow::switchToOpticalMenu() {
    scrollArea->horizontalScrollBar()->setValue(0);
    if(illusionSelectWidget->currentIndex() != 0) {
        illusionSelectWidget->setCurrentIndex(0);
        opticalMenuButton->setIcon(QIcon(ss->opticalMenuButtonIcons[0]));
        audioMenuButton->setIcon(QIcon(ss->audioMenuButtonIcons[1]));
        opticalButtonsList->first()->click();
        audioMediaPlayer->pause();
    }

    restartInteractionTimer();
}

void MainWindow::switchToAudioMenu() {
    scrollArea->horizontalScrollBar()->setValue(0);
    if(illusionSelectWidget->currentIndex() != 1) {
        illusionSelectWidget->setCurrentIndex(1);
        opticalMenuButton->setIcon(QIcon(ss->opticalMenuButtonIcons[1]));
        audioMenuButton->setIcon(QIcon(ss->audioMenuButtonIcons[0]));
        audioButtonsList->first()->click();
        illusionStackedWidget->setCurrentWidget(audioIllusionWidget);
        audioMediaPlayer->play();
    }

    restartInteractionTimer();
}

void MainWindow::nextIllusionSlot() {
    QScrollBar *scrollBar = scrollArea->horizontalScrollBar();
    int startValue = scrollBar->value();
    int endValue = startValue + ss->scrollDistance;

    QPropertyAnimation *animation = new QPropertyAnimation(scrollBar, "value");
    animation->setDuration(ss->scrollDuration);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    restartInteractionTimer();
}

void MainWindow::prevIllusionSlot() {
    QScrollBar *scrollBar = scrollArea->horizontalScrollBar();
    int startValue = scrollBar->value();
    int endValue = startValue - ss->scrollDistance;

    QPropertyAnimation *animation = new QPropertyAnimation(scrollBar, "value");
    animation->setDuration(ss->scrollDuration);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    restartInteractionTimer();
}

void MainWindow::switchToIdleScreen() {
    interactionTimer->stop();

    //Fade in idle widget
    QPropertyAnimation *a = new QPropertyAnimation(idleOpacity,"opacity");
    a->setDuration(ss->fadeDuration);
    a->setStartValue(0);
    a->setEndValue(1);

    //Fade out exhibit widget
    QPropertyAnimation *b = new QPropertyAnimation(exhibitOpacity,"opacity");
    b->setDuration(ss->fadeDuration);
    b->setStartValue(1);
    b->setEndValue(0);

    //Start animations
    b->start(QPropertyAnimation::DeleteWhenStopped);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    a->setPaused(true);

    //Create connections for transition
    connect(b, SIGNAL(finished()), a, SLOT(resume()));
    connect(b, SIGNAL(finished()), this, SLOT(idleStackedSwitch()));
}

void MainWindow::idleStackedSwitch() {
    topStackedWidget->setCurrentWidget(idleWidget);
}

void MainWindow::switchToExhibitScreen() {
    emit switchedToExhibitScreen(0);
    illusionExplanationText->hideText();
    exhibitOpacity->setOpacity(1);
    idleOpacity->setOpacity(0);
    topStackedWidget->setCurrentWidget(exhibitWidget);
}

void MainWindow::pauseInteractionTimer() {
    std::cout << "TIMER PAUSED" << std::endl;
    interactionTimer->stop();
}

void MainWindow::restartInteractionTimer() {
    bool restartAllowed = false;

    VideoWidget* maybeVideo = activeButton->getWidget()->findChild<VideoWidget*>();
    FrameSequenceWidget* maybeFrameSeq = activeButton->getWidget()->findChild<FrameSequenceWidget*>();
    if(maybeVideo != nullptr) {
        restartAllowed = !maybeVideo->isFirstPlay;
    } else if(maybeFrameSeq != nullptr) {
        restartAllowed = !maybeFrameSeq->isFirstPlay;
    } else {
        restartAllowed = true;
    }

    if(restartAllowed) {
        std::cout << "TIMER RESTARTED" + std::to_string(++restartTracker)<< std::endl;
        interactionTimer->start(idleWaitSeconds * 1000);
    }
}

void MainWindow::changeAudioIllusion(QWidget *widget) {
    restartInteractionTimer();

    //Set appropriate button outlining
    activeButton->setStyleSheet("");
    activeButton = (WidgetButton*)sender();
    activeButton->setStyleSheet(ss->activeIllusionButton);

    QString audioPath = static_cast<QLabel*>(widget)->text();
    audioMediaPlayer->setSource(QUrl::fromLocalFile(audioPath));
    audioProgressBar->setRange(0, audioMediaPlayer->duration());
    audioMediaPlayer->play();

    audioIllusionLabel->setText(QFileInfo(audioPath).baseName());
    illusionExplanationText->hideText();
    illusionExplanationText->setText(readFirstLine(audioFileMap->value(audioPath)), readTextExcludingFirstLine(audioFileMap->value(audioPath)));

    visualizer->restartSequence(0);
    visualizer->playSequence();
}

/*
 * Slot function to switch the interface to display a different optical illusion
 *
 * Arguments: QWidget* - optical illusion widget to switch to
 * Returns: void
 */
void MainWindow::changeOpticalIllusion(QWidget *widget) {
    emit switchedActiveIllusion(widget);

     restartInteractionTimer();

    //Set button corresponding to new display illusion to active outline and set old button to standard outline
    activeButton->setStyleSheet("");
     activeButton = dynamic_cast<WidgetButton*>(sender());
    activeButton->setStyleSheet(ss->activeIllusionButton);

    //Change current illusion
    illusionStackedWidget->setCurrentWidget(widget);

    //Set text of new illusion
    QString textPath = opticalFileMap->value(widget);
    illusionExplanationText->hideText();
    illusionExplanationText->setText(readFirstLine(textPath), readTextExcludingFirstLine(textPath));

    //Check if widget is video and play if true
    QMediaPlayer* mediaPlayer = widget->findChild<QMediaPlayer*>();
    if(mediaPlayer != nullptr) {
        mediaPlayer->play();
        return;
    }

    //Check if widget is frame sequence and play if true
    QTimer *timer = widget->findChild<QTimer*>();
    if(timer != nullptr) {
        timer->start();
    }
}

/*
 * Slot function to restart an audio file and the corresponding visualizer
 *
 * Arguments: none
 * Returns: void
 */
void MainWindow::restartAudio() {
    //Restart audio player
    audioMediaPlayer->setPosition(0);
    //Restart and play visualizer
    visualizer->restartSequence(0);
    visualizer->playSequence();
    //Restart interaction timer
    restartInteractionTimer();
}

/*
 * Slot function to set the audio progress bar position to parameter value
 *
 * Arguments: qint64 - value to set the progress bar's position to
 * Returns: void
 */
void MainWindow::setProgressBarPosition(qint64 val) {
    int pos = static_cast<int>(val);
    audioProgressBar->setValue(pos);
}

/*
 * Slot function to handle audio playback state changes
 *
 * Arguments: QMediaPlayer::PlaybackState - state of media player
 * Returns: void
 */
void MainWindow::onPlaybackStateChanged(QMediaPlayer::PlaybackState state) {
    if(isFirstPlayAudio && state != QMediaPlayer::StoppedState) { //If the status change is the video is over
        pauseInteractionTimer();
    }
}


/*
 * Slot function to handle audio media status changes
 *
 * Arguments: QMediaPlayer::MediaStatus - state of media player
 * Returns: void
 */
void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if(isFirstPlayAudio && status == QMediaPlayer::EndOfMedia) { //If the status change is the audio indicates it is over
        isFirstPlayAudio = false; //Set first playthrough flag to false
        restartInteractionTimer();
    }
}

/*
 * Function to filter key presses that should close the program
 *
 * Arguments: QKeyEvent* - key event pointer to filter
 * Returns: void
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Check for Esc, Backspace, and Delete keys to close program
    switch(event->key())
    {
    case Qt::Key_Escape:
    case Qt::Key_Backspace:
    case Qt::Key_Delete:
        close();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

/*
 * Function to filter clicks that should reset the interaction timer
 *
 * Arguments: QKeyEvent* - click event pointer to filter
 * Returns: void
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    restartInteractionTimer();
    QMainWindow::mousePressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

