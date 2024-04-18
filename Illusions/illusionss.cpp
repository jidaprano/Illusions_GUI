#include "illusionss.h"

IllusionSS::IllusionSS() {
    //chalet bold
    int id = QFontDatabase::addApplicationFont(chaletBookBoldPath);
    ChaletBook_Bold = QFont(QFontDatabase::applicationFontFamilies(id).at(0));
    //chalet regular
    id = QFontDatabase::addApplicationFont(chaletBookRegularPath);
    ChaletBook_Regular = QFont(QFontDatabase::applicationFontFamilies(id).at(0));
    //chalet oblique
    id = QFontDatabase::addApplicationFont(chaletBookObliquePath);
    ChaletBook_Oblique = QFont(QFontDatabase::applicationFontFamilies(id).at(0));
}

QPalette IllusionSS::backgroundImage() {
    QPixmap background(backgroundPath);
    background = background.scaled(physicalScreenDimensions, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    return palette;
}

QPalette IllusionSS::idleImage() {
    QPixmap idle(idlePath);
    idle = idle.scaled(physicalScreenDimensions, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, idle);
    return palette;
}
