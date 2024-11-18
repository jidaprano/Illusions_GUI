#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPicture>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QScreen>
#include <QPushButton>
#include <QFileInfo>
#include <QDir>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QMap>
#include <QMessageBox>
#include <QList>
#include <QImageReader>
#include <QProgressBar>
#include <QAudioOutput>
#include <QScrollArea>
#include <QScroller>
#include <QDirIterator>

#include "clickablewidget.h"
#include "widgetbutton.h"
#include "framesequencewidget.h"
#include "videowidget.h" //gives warning but is required
#include "hiddentextwidget.h"
#include "illusionss.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

    int restartTracker = 0;
    int idleWaitSeconds = 60
        ;
    QString opticalFilePath = "./Content/Optical";
    QString audioFilePath = "./Content/Audio";
    QString opticalButtonIconsPath = opticalFilePath + "/ButtonIcons/";
    QString audioButtonIconsPath = audioFilePath + "/ButtonIcons/";

    void importIllusions();
    QString readFirstLine(QString filePath);
    QString readTextExcludingFirstLine(QString filePath);
    QWidget *createOpticalWidget(QString filePath);
    QWidget *createAudioWidget();
    QWidget *getSpacedIllusion(QWidget *illusion);
    QList<QImage> *loadFrameSequence(QString filePath);
    QWidget *createIllusionTypeButtons();
    QWidget *createMenuWidget();
    ClickableWidget *createIdleScreenWidget();

private slots:
    void scrollMenuForward();
    void scrollMenuBackward();
    void switchToOpticalMenu();
    void switchToAudioMenu();
    void switchToIdleScreen();
    void idleStackedSwitch();
    void switchToExhibitScreen();
    void pauseInteractionTimer();
    void restartInteractionTimer();
    void changeAudioIllusion(QWidget* widget);
    void changeOpticalIllusion(QWidget* widget);
    void restartAudio();
    void setProgressBarPosition(qint64 val);
    void onPlaybackStateChanged(QMediaPlayer::PlaybackState state);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

signals:
    void switchedToExhibitScreen(int val);
    void switchedActiveIllusion(QWidget* widget);

private:
    Ui::MainWindow *ui;

    //Style info object
    IllusionSS *ss;

    //Mapping illusions to corresponding text description files
    QMap<QWidget*, QString> *opticalFileMap;
    QMap<QString, QString> *audioFileMap;

    //Top-level stacked widget (swap between exhibit screen and timeout screen)
    QStackedWidget *exhibitAndIdleStackedWidget;

    //Top-level exhibit screen
    QWidget *exhibitWidget;
    QVBoxLayout *exhibitVLayout;

    //Exhibit title widget
    QLabel *title;

    //Illusion widget on exhibit screen
    QStackedWidget *illusionStackedWidget; //contains widgets for all optical illusions and one widget for audio illusions
    QVBoxLayout *illusionVLayout;
    int illusionStackIndex = 0;
    QLabel *opticalIllusionLabel;

    //Audio widget components
    QWidget *audioIllusionWidget;
    QMediaPlayer *audioMediaPlayer;
    QAudioOutput *audioOutput;
    QLabel *audioIllusionLabel;
    QPushButton *audioRestartButton;
    HiddenTextWidget *illusionExplanationText;
    QProgressBar *audioProgressBar;
    FrameSequenceWidget *visualizer;
    bool isFirstPlayAudio = true;

    //Exhibit navigation widget
    QPushButton *audioMenuButton;
    QPushButton *opticalMenuButton;
    QScrollArea *scrollMenu;
    QStackedWidget *illusionSelectWidget;
    QList<WidgetButton*> *opticalButtonsList;
    QList<WidgetButton*> *audioButtonsList;
    WidgetButton *activeButton;
    QScrollArea *scrollArea;

    //Idle widget
    ClickableWidget *idleWidget;
    QTimer *interactionTimer;

    //Opacities
    QGraphicsOpacityEffect *idleOpacity;
    QGraphicsOpacityEffect *exhibitOpacity;

};
#endif // MAINWINDOW_H
