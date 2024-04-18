#ifndef CLICKABLEWIDGET_H
#define CLICKABLEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QPainter>
#include <QStyleOption>

class ClickableWidget : public QWidget
{
    Q_OBJECT
public:
    ClickableWidget();
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *) override;
signals:
    void clicked();
};

#endif // CLICKABLEWIDGET_H
