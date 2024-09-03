#include "videowidget.h"
/**
 * @author Joseph Daprano <joseph.daprano@gmail.com>
 *
 * The VideoWidget class represents a widget that contains a video player
 */

VideoWidget::VideoWidget(QString filePath) : QWidget()
{
    //Setup layout
    layout = new QVBoxLayout(this);

    //Instantiate and add video playing widget
    videoOutput = new QVideoWidget(this);
    layout->addWidget(videoOutput);

    //Instantiate media player object and attach it to the video output widget
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(videoOutput);
    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &VideoWidget::onMediaStatusChanged);

    //Set video file source to parameter path
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));

    isFirstPlay = true;
}

/*
 * Slot function to scrub video to specified value
 *
 * Arguments: int - value to scrub video to
 * Returns: void
 */
void VideoWidget::changePosition(int val) {
    mediaPlayer->setPosition(static_cast<qint64>(val));
}

/*
 * Slot function to pause video
 *
 * Arguments: [unused]int - necessary for connect statement
 * Returns: void
 */
void VideoWidget::pause([[maybe_unused]] int i) {
    mediaPlayer->pause();
}

/*
 * Slot function to play video
 *
 * Arguments: [unused]int - necessary for connect statement
 * Returns: void
 */
void VideoWidget::play([[maybe_unused]] int i) {
    mediaPlayer->play();
}

/*
 * Slot function to handle media status changes
 *
 * Arguments: QMediaPlayer::MediaStatus - status of media player
 * Returns: void
 */
void VideoWidget::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if(isFirstPlay) { //If video has changed during its first playthrough
        if(status == QMediaPlayer::EndOfMedia) { //If the status change is the video is over
            emit firstVideoFinished(); //Emit finished signal
            isFirstPlay = false; //Set first playthrough flag to false
            changePosition(0);
            play(0);
        } else {
            emit firstVideoStarted(); //Emit started signal
        }
    }
}
