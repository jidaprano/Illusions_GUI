#include "framesequencewidget.h"

FrameSequenceWidget::FrameSequenceWidget(QList<QImage> *frameSeq)
{


    this->frameSequence = frameSeq;
    layout = new QVBoxLayout(this);
    image = new QLabel(this);
    pixmap = QPixmap::fromImage(this->frameSequence->first());
    pixmap = pixmap.scaledToWidth(qApp->screens()[0]->size().width() - 200);
    image->setAlignment(Qt::AlignCenter);
    image->setPixmap(pixmap);

    layout->addWidget(image);

    //Scrubber setup
    scrubber = new QImprovedSlider(this);
    scrubber->setOrientation(Qt::Horizontal);
    scrubber->setRange(0, frameSequence->length() - 1);
    connect(scrubber, SIGNAL(valueChanged(int)), this, SLOT(scrubSequence(int)));
    connect(scrubber, SIGNAL(sliderReleased()), this, SLOT(playSequence()));
    connect(scrubber, SIGNAL(sliderPressed()), this, SLOT(pauseSequence()));

    //Timer setup
    autoScrubTimer = new QTimer(this);
    autoScrubTimer->setInterval(24);
    connect(autoScrubTimer, SIGNAL(timeout()), this, SLOT(playSequence()));

    layout->addWidget(scrubber);
    pauseSequence();
}

void FrameSequenceWidget::scrubSequence(int value) {
    if(value >= frameSequence->length() - 1) { //If sequence is over, restart and play
        restartSequence(0);
        playSequence();
    }
    pixmap = QPixmap::fromImage(this->frameSequence->at(value));
    pixmap = pixmap.scaledToWidth(qApp->screens()[0]->size().width() - 200);
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
    scrubber->setValue(scrubber->minimum() + 1);
    pauseSequence();
}
