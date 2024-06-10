#include "framesequencewidget.h"

FrameSequenceWidget::FrameSequenceWidget(QList<QImage> *frameSeq, int interval)
{
    this->frameSequence = frameSeq;
    layout = new QVBoxLayout(this);
    image = new QLabel(this);
    pixmap = QPixmap::fromImage(this->frameSequence->first());
    image->setAlignment(Qt::AlignCenter);
    image->setPixmap(pixmap);
    image->setScaledContents(true);

    layout->addWidget(image);

    //Scrubber setup
    scrubber = new QSlider();
    scrubber->setOrientation(Qt::Horizontal);
    scrubber->setRange(0, frameSequence->length() - 1);
    connect(scrubber, SIGNAL(valueChanged(int)), this, SLOT(scrubSequence(int)));
    connect(scrubber, SIGNAL(sliderReleased()), this, SLOT(playSequence()));
    connect(scrubber, SIGNAL(sliderPressed()), this, SLOT(pauseSequence()));

    //Timer setup
    autoScrubTimer = new QTimer(this);
    autoScrubTimer->setInterval(interval);
    connect(autoScrubTimer, SIGNAL(timeout()), this, SLOT(playSequence()));

    //layout->addWidget(scrubber);
    pauseSequence();
}

void FrameSequenceWidget::scrubSequence(int value) {
    if(value >= frameSequence->length() - 1) { //If sequence is over, restart and play
        restartSequence(0);
        playSequence();
    }
    pixmap = QPixmap::fromImage(this->frameSequence->at(value));
    image->setPixmap(pixmap);
}

void FrameSequenceWidget::playSequence() {
    autoScrubTimer->start();
    int val = scrubber->value();
    scrubber->setValue(++val);
}

void FrameSequenceWidget::pauseSequence() {
    scrubber->setValue(scrubber->value());
    autoScrubTimer->stop();
}

void FrameSequenceWidget::restartSequence(int i) {
    scrubber->setValue(scrubber->minimum());
    pauseSequence();
}
