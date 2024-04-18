#ifndef WIDGETBUTTON_H
#define WIDGETBUTTON_H

#include <QFileInfo>
#include <QToolButton>
#include <QObject>
#include <QWidget>
#include <QIcon>
#include <QImageReader>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaMetaData>
#include <QDir>

class WidgetButton : public QToolButton
{
    Q_OBJECT
public:
    explicit WidgetButton(QWidget *_widget, QString iconPath);
    QWidget *getWidget();
    QString getIconPath();
private:
    QWidget *widget;
    QString iconPath;
    QMediaPlayer *thumbnailPlayer;
    QVideoWidget *thumbnailVideoWidget;
signals:
    void buttonClicked(QWidget *widget);
private slots:
    void emitClickedSignal();
};

#endif // WIDGETBUTTON_H
