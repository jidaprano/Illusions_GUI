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
#include <QSlider>
#include <iostream>

class FrameSequenceWidget : public QWidget
{
    Q_OBJECT
public:
    FrameSequenceWidget(QList<QImage> *frameSeq, int interval, QWidget* parent);
    QList<QImage> *frameSequence;
    bool isFirstPlay;
private:
    QLabel *image;
    QVBoxLayout *layout;
    QPixmap pixmap;
    QSlider *scrubber;
    QTimer *autoScrubTimer;
public slots:
    void scrubSequence(int value);
    void playSequence();
    void pauseSequence();
    void restartSequence(int i);
    void resetIsFirstPlay(int i);
signals:
    void firstSequenceStarted();
    void firstSequenceFinished();
};

#endif // FRAMESEQUENCEWIDGET_H
