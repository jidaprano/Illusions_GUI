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
    FrameSequenceWidget(QList<QImage> *frameSeq);
    QList<QImage> *frameSequence;
private:
    QLabel *image;
    QVBoxLayout *layout;
    QPixmap pixmap;
    QImprovedSlider *scrubber;
    QTimer *autoScrubTimer;
public slots:
    void scrubSequence(int value);
    void playSequence();
    void pauseSequence();
    void restartSequence(int i);
};

#endif // FRAMESEQUENCEWIDGET_H
