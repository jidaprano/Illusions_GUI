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
    bool isFirstPlay;
private slots:
    void changePosition(int);
    void pause(int i);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
signals:
    void videoStarted();
    void videoFinished();
};

#endif // VIDEOWIDGET_H
