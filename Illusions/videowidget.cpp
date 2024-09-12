#include "videowidget.h"
/**
 * @author Joseph Daprano <joseph.daprano@gmail.com>
 *
 * The VideoWidget class represents a widget that contains a video player
 */

VideoWidget::VideoWidget(QString filePath, QWidget* parent) : QWidget(parent)
{

    //Setup parenting
    this->setParent(parent);

    //Setup first play tracker
    isFirstPlay = true;

    //Setup active illusion tracker
    activeWidget = this;

    //Setup layout
    layout = new QVBoxLayout(this);

    //Instantiate and add video playing widget
    videoOutput = new QVideoWidget(this);
    layout->addWidget(videoOutput);

    //Instantiate media player object and attach it to the video output widget
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(videoOutput);
    connect(mediaPlayer, SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)),
            this, SLOT(onPlaybackStateChanged(QMediaPlayer::PlaybackState)));
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(checkPosition(qint64)));
    connect(mediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(onMediaStatusChanged(QMediaPlayer::MediaStatus)));

    //Set video file source to parameter path
    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
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
 * Slot function to restart and pause video
 *
 * Arguments: [unused]int - necessary for connect statement
 * Returns: void
 */
void VideoWidget::resetAndPause([[maybe_unused]] int i) {
    isFirstPlay = true;
    changePosition(0);
    pause(0);
}

/*
 * Slot function to restart and play video
 *
 * Arguments: [unused]int - necessary for connect statement
 * Returns: void
 */
void VideoWidget::resetAndPlay([[maybe_unused]] int i) {
    isFirstPlay = true;
    changePosition(0);
    play(0);
}

void VideoWidget::checkPosition(qint64 pos) {

}


/*
 * Slot function to handle media status changes
 *
 * Arguments: QMediaPlayer::PlaybackState - state of media player
 * Returns: void
 */
void VideoWidget::onPlaybackStateChanged(QMediaPlayer::PlaybackState state) {
    if(isFirstPlay) { //If video has changed during its first playthrough
        QMediaPlayer* activeMediaPlayer = activeWidget->findChild<QMediaPlayer*>();
        if(activeMediaPlayer != nullptr && activeMediaPlayer->source() == this->mediaPlayer->source()) {
            if(state != QMediaPlayer::StoppedState) { //If the status change is the video is over
                emit firstVideoStarted(); //Emit started signal
            }
        }
    }
}

void VideoWidget::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if(isFirstPlay) { //If video has changed during its first playthrough
        QMediaPlayer* activeMediaPlayer = activeWidget->findChild<QMediaPlayer*>();
        if(activeMediaPlayer != nullptr && activeMediaPlayer->source() == this->mediaPlayer->source()) {
            if(status == QMediaPlayer::EndOfMedia) { //If the status change is the video is over
                emit firstVideoFinished(); //Emit finished signal
                isFirstPlay = false; //Set first playthrough flag to false
                changePosition(0);
                play(0);
            }
        }
    }
}

/*
 * Slot function to update tracker for current active widget
 *
 * Arguments: [unused]int - necessary for connect statement
 * Returns: void
 */
void VideoWidget::updateActiveWidget(QWidget* widget) {
    activeWidget = widget;
}

