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

    //Import soundwave frame sequence
    soundwaveSeq = new QList<QImage>();
    QFileInfoList soundwaveFiles = QDir(soundwavePath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for(QFileInfo file : soundwaveFiles) {
        soundwaveSeq->insert(0, QImage(file.absoluteFilePath()));
    }
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

QList<QImage>* IllusionSS::getSoundwaveSeq() {
    return soundwaveSeq;
}
