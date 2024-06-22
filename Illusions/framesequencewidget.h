#ifndef FRAMESEQUENCEWIDGET_H
#define FRAMESEQUENCEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScrollBar>
#include <QAbstractSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <QTimer>
#include <iostream>
#include "qimprovedslider.h"

class FrameSequenceWidget : public QWidget
{
    Q_OBJECT
public:
    FrameSequenceWidget(QList<QImage> *frameSeq, int interval);
    QList<QImage> *frameSequence;
private:
    QLabel *image;
    QVBoxLayout *layout;
    QPixmap pixmap;
    QSlider *scrubber;
    QTimer *autoScrubTimer;
    bool isFirstPlay;
public slots:
    void scrubSequence(int value);
    void playSequence();
    void pauseSequence();
    void restartSequence(int i);
signals:
    void sequenceStarted();
    void sequenceFinished();
};

#endif // FRAMESEQUENCEWIDGET_H
