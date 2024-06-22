#include "videowidget.h"

VideoWidget::VideoWidget(QString filePath) : QWidget()
{
    layout = new QVBoxLayout(this);

    videoOutput = new QVideoWidget;
    layout->addWidget(videoOutput);

    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(videoOutput);

    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &VideoWidget::onMediaStatusChanged);

    isFirstPlay = true;
}

void VideoWidget::changePosition(int val) {
    mediaPlayer->setPosition(static_cast<qint64>(val));
}

void VideoWidget::pause([[maybe_unused]] int i) {
    mediaPlayer->pause();
}

void VideoWidget::onMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if(isFirstPlay) {
        if(status == QMediaPlayer::EndOfMedia) {
            emit videoFinished();
            isFirstPlay = false;
        } else {
            emit videoStarted();
        }
    }
}
