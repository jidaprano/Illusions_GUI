#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QScrollBar>
#include <QAbstractSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <iostream>
#include "qimprovedslider.h"

class VideoWidget : public QWidget
{
    Q_OBJECT
public:
    VideoWidget(QString filePath);
private:
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoOutput;
    QVBoxLayout *layout;
    QImprovedSlider *scrubber;
private slots:
    void changePosition(int);
    void changeScrubberLocation(qint64);
    void pause(int i);
};

#endif // VIDEOWIDGET_H
