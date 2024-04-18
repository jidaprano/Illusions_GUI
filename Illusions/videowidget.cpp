#include "videowidget.h"

VideoWidget::VideoWidget(QString filePath) : QWidget()
{
    layout = new QVBoxLayout(this);

    videoOutput = new QVideoWidget;
    layout->addWidget(videoOutput);

    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(videoOutput);

    mediaPlayer->setSource(QUrl::fromLocalFile(filePath));

    scrubber = new QImprovedSlider(this);
    scrubber->setOrientation(Qt::Horizontal);
    scrubber->setRange(0, mediaPlayer->duration());
    connect(scrubber, SIGNAL(sliderPressed()), mediaPlayer, SLOT(pause()));
    connect(scrubber, SIGNAL(sliderReleased()), mediaPlayer, SLOT(play()));
    connect(scrubber, SIGNAL(sliderMoved(int)), this, SLOT(changePosition(int)));
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(changeScrubberLocation(qint64)));
    layout->addWidget(scrubber);
}

void VideoWidget::changePosition(int val) {
    mediaPlayer->setPosition(static_cast<qint64>(val));
}

void VideoWidget::changeScrubberLocation(qint64 pos) {
    scrubber->setSliderPosition(static_cast<int>(pos));
}

void VideoWidget::pause(int i) {
    mediaPlayer->pause();
}

