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

    //Stylesheets
    QString menuButton =
        "QToolButton {"
        "border: 10px solid #eb9834; }"
        ;

    QString labelColor =
        "QLabel {"
        "color: rgb(123, 45, 25); }"
        ;

    //Sizing and spacing
    QSize physicalScreenDimensions = QSize(1080, 1920);
    QMargins overallMargins = QMargins(50, 50, 50, 50);

    //Fonts
    QFont ChaletBook_Bold;
    QFont ChaletBook_Regular;
    QFont ChaletBook_Oblique;

    //Functions
    QPalette backgroundImage();
    QPalette idleImage();
};

#endif // ILLUSIONSS_H
