#ifndef ILLUSIONSS_H
#define ILLUSIONSS_H

#include <QString>
#include <QPixmap>
#include <QPalette>
#include <QFontDatabase>

class IllusionSS
{
public:
    IllusionSS();

    //Paths
    QString chaletBookBoldPath = ":/fonts/StyleResources/Fonts/ChaletBook-Bold_10028 2.ttf";
    QString chaletBookRegularPath = ":/fonts/StyleResources/Fonts/ChaletBook_10032 2.ttf";
    QString chaletBookObliquePath = ":/fonts/StyleResources/Fonts/ChaletOblique-London.ttf";
    QString backgroundPath = ":/images/StyleResources/Illusions_Background_APR24.png";
    QString idlePath = ":/images/StyleResources/idleScreen.png";
    QString audioMenuButtonIcons[2] = { ":/images/StyleResources/Illusions_Red-Auditory-Button_APR24.png",
                                      ":/images/StyleResources/Illusions_Brown-Auditory-Button_APR24.png" };
    QString opticalMenuButtonIcons[2] = { ":/images/StyleResources/Illusions_Red-Optical-Button_APR24.png",
                                        ":/images/StyleResources/Illusions_Brown-Optical-Button_APR24.png" };

    //EVIL PATH MUST BE HANDLED
    QString visualizerPath = "/home/exhibits/Desktop/IllusionsProject/Illusions_GUI/Illusions/StyleResources/soundwave.mp4";

    //Stylesheets
    QString activeIllusionButton =
        "QToolButton {"
        "border: 4px solid #7b2d19; }"
        ;

    QString labelColor =
        "QLabel {"
        "color: rgb(123, 45, 25); }"
        ;

    QString hiddenTextButtonStyle = "QPushButton {text-align: left;"
                                    "background-color: #dfd7b8;"
                                    "color: rgb(123, 45, 25);}";

    QString scrollAreaStyle = "QScrollArea {background-color:transparent;"
                              "border: 4px solid #7b2d19; }";
    QString illusionSelectStyle = "QStackedWidget {background-color:transparent;}";
    QString illusionTypeButtonStyle = "QPushButton {background-color:transparent;}";
    QString audioWidgetStyle = "QWidget {background-color:white;}"
                               "QPushButton {color: rgb(123, 45, 25);}";
    QString audioProgressBarStyle = "QProgressBar {"
                                    "background-color: #dfd7b8; "
                                    "border: 0px;"
                                    "border-radius: 10px;"
                                    "}"
                                    "QProgressBar::chunk:horizontal {"
                                    "background-color: #b23428;"
                                    "border-bottom-left-radius: 10px;"
                                    "border-top-left-radius: 10px;"
                                    "}";

    //Sizing and spacing
    QSize physicalScreenDimensions = QSize(1080, 1920);
    QMargins overallMargins = QMargins(50, 50, 50, 50);
    QSize illusionButtonSize = QSize(125,125);
    QSize illusionTypeButtonSize = QSize(255,87);
    QSize illusionSize = QSize(700,700);
    int illusionSideMargin = 125;

    //Fonts
    QFont ChaletBook_Bold;
    QFont ChaletBook_Regular;
    QFont ChaletBook_Oblique;

    //Functions
    QPalette backgroundImage();
    QPalette idleImage();
};

#endif // ILLUSIONSS_H
