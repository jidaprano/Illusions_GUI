#ifndef ILLUSIONSS_H
#define ILLUSIONSS_H

#include <QString>
#include <QPixmap>
#include <QPalette>
#include <QFontDatabase>
#include <QDir>

class IllusionSS
{
public:
    IllusionSS();

    //Paths
    const QString chaletBookBoldPath = ":/fonts/StyleResources/Fonts/ChaletBook-Bold_10028 2.ttf";
    const QString chaletBookRegularPath = ":/fonts/StyleResources/Fonts/ChaletBook_10032 2.ttf";
    const QString chaletBookObliquePath = ":/fonts/StyleResources/Fonts/ChaletOblique-London.ttf";
    const QString backgroundPath = ":/images/StyleResources/Illusions_Background_APR24.png";
    const QString idlePath = ":/images/StyleResources/idleScreen.png";
    const QString audioMenuButtonIcons[2] = { ":/images/StyleResources/Illusions_Red-Auditory-Button_APR24.png",
                                      ":/images/StyleResources/Illusions_Brown-Auditory-Button_APR24.png" };
    const QString opticalMenuButtonIcons[2] = { ":/images/StyleResources/Illusions_Red-Optical-Button_APR24.png",
                                        ":/images/StyleResources/Illusions_Brown-Optical-Button_APR24.png" };
    const QString soundwavePath = ":/soundwaveSequence/StyleResources/soundwave";
    const QString forwardButtonPath = ":/images/StyleResources/Illusions_Right-Arrow_APR24.png";
    const QString backButtonPath = ":/images/StyleResources/Illusions_Left-Arrow_APR24.png";

    //Stylesheets
    const QString activeIllusionButton =
        "QToolButton {"
        "border: 4px solid #7b2d19;"
        "background-color: white; }"
        ;

    const QString inactiveIllusionButton =
        "QToolButton {"
        "background-color: white; }"
        ;

    const QString labelColor =
        "QLabel {"
        "color: rgb(123, 45, 25); }"
        ;

    const QString hiddenTextButtonStyle = "QPushButton {"
                                    " background-color: #b23428;"
                                    "border-style: solid;"
                                    "border-width:10px;"
                                    "border-radius:50px;"
                                    "border-color: #7b2d19;"
                                    "max-width:100px;"
                                    "max-height:100px;"
                                    "min-width:100px;"
                                    "min-height:100px;"
                                    "}";

    const QString scrollAreaStyle = "QScrollArea {background-color:transparent;"
                              "border: 4px solid #7b2d19; }";
    const QString illusionSelectStyle = "QStackedWidget {background-color:transparent;}";
    const QString illusionTypeButtonStyle = "QPushButton {background-color:transparent;}";
    const QString audioWidgetStyle = "QWidget {background-color:white;}"
                               "QPushButton {color: rgb(123, 45, 25);}";
    const QString audioProgressBarStyle = "QProgressBar {"
                                    "background-color: #dfd7b8; "
                                    "border: 0px;"
                                    "}"
                                    "QProgressBar::chunk:horizontal {"
                                    "background-color: #b23428;"
                                    "width: 1px;"
                                    "}";
    const QString menuScrollButtonStyle = "QToolButton {"
                                    "border: 0px solid #dfd7b8; }"
        ;

    //Sizing and spacing
    const QSize physicalScreenDimensions = QSize(1080, 1920);
    const QMargins exhibitMargins = QMargins(50,50,50,50);
    const QMargins idleMargins = QMargins(0,0,0,0);
    const QSize illusionButtonSize = QSize(170,170);
    const QSize illusionTypeButtonSize = QSize(255,87);
    const QSize menuBackForwardButtonSize = QSize(50, 50);
    const QSize illusionSize = QSize(700,700);
    const int illusionSideMargin = 125;
    const int fadeDuration = 1000;
    const int scrollDuration = 300;
    const int scrollDistance = 100;
    const int scrollAreaButtonSpacing = 15;
    const int scrollAreaHeight = 200;

    //Fonts
    QFont ChaletBook_Bold;
    QFont ChaletBook_Regular;
    QFont ChaletBook_Oblique;

    //Frame sequence intervals
    const int visualizerInterval = 38;
    const int defaultInterval = 24;

    //Functions
    QPalette backgroundImage();
    QPalette idleImage();
    QList<QImage>* getSoundwaveSeq();
    QString getEmptyFileMessage(QString fileName);

    //Error messages
    const QString warningTitle = "Warning";

    //Valid suffix lists
    const QList<QString> audioFileSuffixes = { "mp3", "ogg", "WAV", "wav" };
    const QList<QString> videoFileSuffixes = { "mp4", "mov", "m4v" };
private:
    QList<QImage> *soundwaveSeq;
};

#endif // ILLUSIONSS_H
