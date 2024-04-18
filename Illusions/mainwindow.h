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

#include "clickablewidget.h"
#include "widgetbutton.h"
#include "framesequencewidget.h"
#include "videowidget.h"
#include "hiddentextwidget.h"
#include "qimprovedslider.h"
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

    int idleWaitSeconds = 300
        ;
    QString opticalFilePath = "./Content/Optical";
    QString audioFilePath = "./Content/Audio";
    QString opticalButtonIconsPath = opticalFilePath + "/images/ButtonIcons/";
    QSize *buttonIconSize = new QSize(180,180);

    void initializeFileMaps();
    QString readTextFromFile(QString filePath);
    void importIllusions();
    QWidget *createOpticalWidget(QString filePath);
    QWidget *createAudioWidget();
    QList<QImage> *loadFrameSequence(QString filePath);
    QScrollArea *createMenuWidget();
    ClickableWidget *createIdleScreenWidget();

private slots:
    void nextIllusionSlot();
    void prevIllusionSlot();
    void switchIllusionMenu();
    void switchToIdleScreen();
    void idleStackedSwitch();
    void switchToExhibitScreen();
    void changeAudioIllusion(QWidget* widget);
    void changeOpticalIllusion(QWidget* widget);
    void restartAudio();
    void setProgressBarPosition(qint64 val);

private:
    Ui::MainWindow *ui;

    //Style info object
    IllusionSS *ss;

    //Mapping illusions to corresponding text description files
    QMap<QString, QString> *opticalFileMap;
    QMap<QString, QString> *audioFileMap;

    //Top-level stacked widget (swap between exhibit screen and timeout screen)
    QStackedWidget *topStackedWidget;

    //Top-level exhibit screen
    QWidget *exhibitWidget;
    QVBoxLayout *exhibitVLayout;

    //Exhibit title widget
    QLabel *title;

    //Illusion widget on exhibit screen
    QStackedWidget *illusionStackedWidget;
    QVBoxLayout *illusionVLayout;
    int illusionStackIndex = 0;
    QLabel *opticalIllusionLabel;

    //Audio widget components
    QWidget *audioIllusionWidget;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    QLabel *audioIllusionLabel;
    QPushButton *audioRestartButton;
    HiddenTextWidget *illusionExplanationText;
    QProgressBar *audioProgressBar;

    //Exhibit navigation widget
    QPushButton *menuSwitchButton;
    QScrollArea *scrollMenu;
    QStackedWidget *menuWidget;
    QList<WidgetButton*> *opticalButtonsList;
    QList<WidgetButton*> *audioButtonsList;

    //Text widget on exhibit screen
    //QLabel *illusionExplanationText;

    //Idle widget
    ClickableWidget *idleWidget;
    QTimer *interactionTimer;

    //Opacities
    QGraphicsOpacityEffect *idleOpacity;
    QGraphicsOpacityEffect *exhibitOpacity;

};
#endif // MAINWINDOW_H
