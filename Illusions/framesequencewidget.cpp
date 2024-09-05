#include "framesequencewidget.h"

//FrameSequenceWidget constructor
FrameSequenceWidget::FrameSequenceWidget(QList<QImage> *frameSeq, int interval)
{
    //Set this object's list of images to the parameter value
    this->frameSequence = frameSeq;

    //Organize layout
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

    //Timer setup
    autoScrubTimer = new QTimer(this);
    autoScrubTimer->setInterval(interval);
    connect(autoScrubTimer, SIGNAL(timeout()), this, SLOT(playSequence()));

    pauseSequence();
    isFirstPlay = true;
}

/*
 * Slot function to scrub sequence to frame specified by parameter
 *
 * Arguments: int - value to scrub sequence to
 * Returns: void
 */
void FrameSequenceWidget::scrubSequence(int value) {
    if(value >= frameSequence->length() - 1) { //If sequence is over, restart and play
        restartSequence(0);
        playSequence();
        if(isFirstPlay) { //If sequence has finished its first playthrough, change isFirstPlay flag and emit finished signal
            emit firstSequenceFinished();
            isFirstPlay = false;
        }
    }

    //Set sequence image to place in frame list specified by parameter value
    pixmap = QPixmap::fromImage(this->frameSequence->at(value));
    image->setPixmap(pixmap);
}

/*
 * Slot function to start sequence playing
 *
 * Arguments: none
 * Returns: void
 */
void FrameSequenceWidget::playSequence() {
    if(isFirstPlay) {
        emit firstSequenceStarted();
    }
    autoScrubTimer->start();
    int val = scrubber->value();
    scrubber->setValue(++val);
}

/*
 * Slot function to pause playing sequence
 *
 * Arguments: none
 * Returns: void
 */
void FrameSequenceWidget::pauseSequence() {
    scrubber->setValue(scrubber->value());
    autoScrubTimer->stop();
}

/*
 * Slot function to restart sequence and pause its playing
 *
 * Arguments: int - required for connect statement but unused
 * Returns: void
 */
void FrameSequenceWidget::restartSequence([[maybe_unused]] int i) {
    scrubber->setValue(scrubber->minimum());
    pauseSequence();
}

/*
 * Slot function to set isFirstPlay to true
 *
 * Arguments: int - required for connect statement but unused
 * Returns: void
 */
void FrameSequenceWidget::resetIsFirstPlay([[maybe_unused]] int i) {
    isFirstPlay = true;
}
