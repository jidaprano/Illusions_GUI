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
public slots:
    void changePosition(int);
    void play(int i);
    void pause(int i);
    void onPlaybackStateChanged(QMediaPlayer::PlaybackState status);
    void resetIsFirstPlay(int i);
signals:
    void firstVideoStarted();
    void firstVideoFinished();
};

#endif // VIDEOWIDGET_H
