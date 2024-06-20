#include "videowidget.h"

VideoWidget::VideoWidget(QString filePath) : QWidget()
{
    layout = new QVBoxLayout(this);

    videoOutput = new QVideoWidget;
    layout->addWidget(videoOutput);

    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(videoOutput);

    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
}

void VideoWidget::changePosition(int val) {
    mediaPlayer->setPosition(static_cast<qint64>(val));
}

void VideoWidget::pause([[maybe_unused]] int i) {
    mediaPlayer->pause();
}

