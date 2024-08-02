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

/*
 * Function to return correctly formatted background image
 *
 * Arguments: none
 * Returns: QPalette - formatted background palette
 */
QPalette IllusionSS::backgroundImage() {
    QPixmap background(backgroundPath);
    background = background.scaled(physicalScreenDimensions, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    return palette;
}

/*
 * Function to return correctly formatted idle screen image
 *
 * Arguments: none
 * Returns: QPalette - formatted idle screen palette
 */
QPalette IllusionSS::idleImage() {
    QPixmap idle(idlePath);
    idle = idle.scaled(physicalScreenDimensions, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, idle);
    return palette;
}

/*
 * Function to get the list of images in the soundwave visualizer sequence
 *
 * Arguments: none
 * Returns: QPalette - formatted background palette
 */
QList<QImage>* IllusionSS::getSoundwaveSeq() {
    return soundwaveSeq;
}

/*
 * Function to return formatted empty file error string
 *
 * Arguments: QString - filepath that is empty
 * Returns: QString - formatted error message
 */
QString IllusionSS::getEmptyFileMessage(QString fileName) {
    return "The file " + fileName + " is empty.";
}
