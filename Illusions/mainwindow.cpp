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

    //Initialize and populate file path maps from illusion to text description
    initializeFileMaps();

    //Top-level layered widget
    topStackedWidget = new QStackedWidget(this);

    //Top-level exhibit widget
    exhibitWidget = new QWidget(topStackedWidget);
    exhibitVLayout = new QVBoxLayout(exhibitWidget);
    exhibitVLayout->setContentsMargins(ss->overallMargins);
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

    //Create text explanation widget
    illusionExplanationText = new HiddenTextWidget("", "");

    //Import optical and audio illusions
    importIllusions();
    audioIllusionWidget = createAudioWidget();
    illusionStackedWidget->addWidget(audioIllusionWidget);
    exhibitVLayout->addWidget(illusionStackedWidget);

    //Add text explanation to layout
    illusionExplanationText->setMaximumHeight(300);
    exhibitVLayout->addWidget(illusionExplanationText);

    //Illusion select widget
    QWidget* menuWidget = createMenuWidget();
    illusionSelectWidget->setCurrentIndex(0);
    exhibitVLayout->addWidget(menuWidget);

    //Select first illusion
    //opticalButtonsList->first()->click();
    activeButton = opticalButtonsList->first();
    opticalButtonsList->first()->click();

    //Idle screen widget
    idleWidget = createIdleScreenWidget();
    //instantiate opacity for idle screen
    idleOpacity = new QGraphicsOpacityEffect(this);
    idleWidget->setGraphicsEffect(idleOpacity);
    idleOpacity->setOpacity(0);

    //Idle screen timer
    interactionTimer = new QTimer(this);
    connect(interactionTimer, SIGNAL(timeout()), this, SLOT(switchToIdleScreen()));
    interactionTimer->start(idleWaitSeconds * 1000);

    //Add background image
    QPalette backgroundImage = ss->backgroundImage();
    this->setPalette(backgroundImage);

    //Add all created widgets to top-level stacked widget and set central widget
    topStackedWidget->addWidget(exhibitWidget);
    topStackedWidget->addWidget(idleWidget);
    topStackedWidget->setCurrentWidget(exhibitWidget);
    this->setCentralWidget(topStackedWidget);
}

void MainWindow::initializeFileMaps() {
    //Instantiate maps
    opticalFileMap = new QMap<QString, QString>();
    audioFileMap = new QMap<QString, QString>();

    //Create optical file lists to search through
    QFileInfoList imageFileList = QDir(opticalFilePath + "/images").entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    QDir opticalTextDir = QDir(opticalFilePath + "/text");

    for(QFileInfo file : imageFileList) { //for each file in folder
        if(opticalTextDir.exists(file.baseName())) { //if the file has a matching file in text folder
            opticalFileMap->insert(file.absoluteFilePath(), opticalTextDir.absoluteFilePath(file.baseName())); //add the pair to the map
        }
    }

    //Create audio file lists to search through
    QFileInfoList audioFileList = QDir(audioFilePath + "/audios").entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    QDir audioTextDir = QDir(audioFilePath + "/text");

    for(QFileInfo file : audioFileList) { //for each file in folder
        if(audioTextDir.exists(file.baseName())) { //if the file has a matching file in text folder
            audioFileMap->insert(file.absoluteFilePath(), audioTextDir.absoluteFilePath(file.baseName())); //add the pair to the map
        }
    }
}

void MainWindow::importIllusions() {
    //Create illusion widget for each illusion in optical map
    for(QString filePath : opticalFileMap->keys()) {
        QWidget *illusion = createOpticalWidget(filePath);
        QString iconPath = opticalButtonIconsPath + QFileInfo(filePath).baseName() + ".jpg";
        WidgetButton *button = new WidgetButton(illusion, iconPath);
        button->setIconSize(ss->illusionButtonSize);
        button->setMaximumSize(ss->illusionButtonSize);
        opticalButtonsList->push_front(button);
        illusionStackedWidget->addWidget(illusion);
        connect(button, SIGNAL(buttonClicked(QWidget*)), this, SLOT(changeOpticalIllusion(QWidget*)));
    }

    //Create button for each audio widget and add to list
    for(QString filePath : audioFileMap->keys()) {
        QLabel *illusion = new QLabel(filePath);
        QString iconPath = audioButtonIconsPath + QFileInfo(filePath).baseName() + ".jpg";
        WidgetButton *button = new WidgetButton(illusion, iconPath);
        button->setIconSize(ss->illusionButtonSize);
        button->setMaximumSize(ss->illusionButtonSize);
        audioButtonsList->push_front(button);
        connect(button, SIGNAL(buttonClicked(QWidget*)), this, SLOT(changeAudioIllusion(QWidget*)));
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

    //File is single image
    if(QFileInfo(filePath).isFile() && !QImageReader::imageFormat(filePath).isNull()) {
        //Create illusion icon and add to layout
        QLabel *illusion = new QLabel(illusionWidget);
        QPixmap *illusionIcon = new QPixmap();
        illusionIcon->load(filePath);
        *illusionIcon = illusionIcon->scaledToWidth(qApp->screens()[0]->size().width() - 200);
        illusion->setAlignment(Qt::AlignCenter);
        illusion->setPixmap(*illusionIcon);
        //Sizing and spacing
        illusionLayout->addWidget(getSpacedIllusion(illusion));
    } else if(QFileInfo(filePath).isDir()){ //File is folder, so illusion is frame sequence
        QList<QImage> *frameList = loadFrameSequence(filePath);
        FrameSequenceWidget *frameSeq = new FrameSequenceWidget(frameList);
        //Sizing and spacing
        illusionLayout->addWidget(getSpacedIllusion(frameSeq));
        connect(illusionStackedWidget, SIGNAL(currentChanged(int)), frameSeq, SLOT(restartSequence(int)));
    } else { //File is video
        VideoWidget *videoWidget = new VideoWidget(filePath);
        //Sizing and spacing
        illusionLayout->addWidget(getSpacedIllusion(videoWidget));
        connect(illusionStackedWidget, SIGNAL(currentChanged(int)), videoWidget, SLOT(pause(int)));
    }

    return illusionWidget;
}

QWidget* MainWindow::createAudioWidget() {
    QWidget *audioIllusionWidget = new QWidget(this);
    QVBoxLayout *audioIllusionLayout = new QVBoxLayout(audioIllusionWidget);

    audioMediaPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    videoMediaPlayer = new QMediaPlayer;
    videoOutput = new QVideoWidget;

    //Audio setup
    audioMediaPlayer->setAudioOutput(audioOutput);

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

    //Soundwave visualizer
    connect(videoMediaPlayer,&QMediaPlayer::mediaStatusChanged,videoMediaPlayer,&QMediaPlayer::play);
    videoMediaPlayer->setSource(QUrl::fromLocalFile(ss->visualizerPath));
    videoMediaPlayer->setVideoOutput(videoOutput);
    videoOutput->setAspectRatioMode(Qt::IgnoreAspectRatio);
    secondAudioLayout->addSpacing(125);
    secondAudioLayout->addWidget(videoOutput);
    secondAudioLayout->addSpacing(100);
    videoMediaPlayer->play();

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
        QMessageBox::information(0, "error reading text file " + filePath, file.errorString());
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
        QMessageBox::information(0, "error reading text file " + filePath, file.errorString());
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
        QWidget* button = audioButtonsList->at(i);
        audioSelectLayout->addWidget(button);
    }
    illusionSelectWidget->addWidget(audioSelectWidget);
    illusionSelectWidget->setStyleSheet(ss->illusionSelectStyle);

//    QPushButton *prevButton = new QPushButton("Previous Illusion");
//    connect(prevButton, SIGNAL(clicked(bool)), this, SLOT(prevIllusionSlot()));

//    QPushButton *nextButton = new QPushButton("Next Illusion");
//    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(nextIllusionSlot()));

//    illusionSelectLayout->addWidget(prevButton);
//    illusionSelectLayout->addWidget(nextButton);

    //QScrollArea setup
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(illusionSelectWidget);

    // hide scrollbars
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Set style and dimensions
    scrollArea->setStyleSheet(ss->scrollAreaStyle);
    scrollArea->setMaximumHeight(200);
    // configure gesture and add rubberband effect
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    //Create layout to hold menu for switching between illusions AND for switching between types of illusions
    QHBoxLayout *topMenuLayout = new QHBoxLayout(topMenuWidget);
    topMenuLayout->addWidget(scrollArea);
    topMenuLayout->addWidget(createIllusionTypeButtons());

    //Set illusionSelectWidget to be able to switch between menus
    this->illusionSelectWidget = illusionSelectWidget;

    return topMenuWidget;
}

ClickableWidget* MainWindow::createIdleScreenWidget() {
    ClickableWidget *idleWidget = new ClickableWidget();
    QVBoxLayout *idleLayout = new QVBoxLayout((QWidget*)idleWidget);
    QLabel *idlePicture = new QLabel();
    QPixmap illusionIcon;
    QRect dimensions(0, 0, 1080, 1920);
    illusionIcon.load("/home/exhibits/Desktop/illusionsContentDemo/output-onlinetools (1).png");
    //illusionIcon = illusionIcon.scaledToHeight(qApp->screens()[0]->size().height());
    idlePicture->setPixmap(illusionIcon.copy(dimensions));

    idleLayout->addWidget(idlePicture);
    // QPalette idlePalette = ss->idleImage();
    // idleWidget->setPalette(idlePalette);
    connect(idleWidget, SIGNAL(clicked()), this, SLOT(switchToExhibitScreen()));

    return idleWidget;
}

void MainWindow::switchToOpticalMenu() {
    if(illusionSelectWidget->currentIndex() != 0) {
        illusionSelectWidget->setCurrentIndex(0);
        opticalMenuButton->setIcon(QIcon(ss->opticalMenuButtonIcons[0]));
        audioMenuButton->setIcon(QIcon(ss->audioMenuButtonIcons[1]));
        opticalButtonsList->first()->click();
        audioMediaPlayer->pause();
    }
}

void MainWindow::switchToAudioMenu() {
    if(illusionSelectWidget->currentIndex() != 1) {
        illusionSelectWidget->setCurrentIndex(1);
        opticalMenuButton->setIcon(QIcon(ss->opticalMenuButtonIcons[1]));
        audioMenuButton->setIcon(QIcon(ss->audioMenuButtonIcons[0]));
        audioButtonsList->first()->click();
        illusionStackedWidget->setCurrentWidget(audioIllusionWidget);
        audioMediaPlayer->play();
    }
}

void MainWindow::nextIllusionSlot() {
    if(illusionStackIndex < (illusionStackedWidget->count() - 1)) {
        illusionStackIndex++;
        illusionStackedWidget->setCurrentIndex(illusionStackIndex);
    }
}

void MainWindow::prevIllusionSlot() {
    if(illusionStackIndex > 0) {
        illusionStackIndex--;
        illusionStackedWidget->setCurrentIndex(illusionStackIndex);
    }
}

void MainWindow::switchToIdleScreen() {
    interactionTimer->stop();

    //Fade in idle widget
    QPropertyAnimation *a = new QPropertyAnimation(idleOpacity,"opacity");
    a->setDuration(2500);
    a->setStartValue(0);
    a->setEndValue(1);

    //Fade out exhibit widget
    QPropertyAnimation *b = new QPropertyAnimation(exhibitOpacity,"opacity");
    b->setDuration(2500);
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
    exhibitOpacity->setOpacity(1);
    idleOpacity->setOpacity(0);
    topStackedWidget->setCurrentWidget(exhibitWidget);
    interactionTimer->start(idleWaitSeconds * 1000);
}

void MainWindow::changeAudioIllusion(QWidget *widget) {
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
}

void MainWindow::changeOpticalIllusion(QWidget *widget) {
    //Set appropriate button outlining
    activeButton->setStyleSheet("");
    activeButton = (WidgetButton*)sender();
    activeButton->setStyleSheet(ss->activeIllusionButton);

    //Change current illusion
    illusionStackedWidget->setCurrentWidget(widget);

    //Set text of new illusion
    QLabel* opticalLabel = widget->findChild<QLabel*>();
    QString textPath = opticalFilePath + "/text/" + opticalLabel->text();
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

void MainWindow::restartAudio() {
    audioMediaPlayer->setPosition(0);
}

void MainWindow::setProgressBarPosition(qint64 val) {
    int pos = static_cast<int>(val);
    audioProgressBar->setValue(pos);
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
        close();
        break;
    case Qt::Key_Backspace:
        close();
        break;
    case Qt::Key_Delete:
        close();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

