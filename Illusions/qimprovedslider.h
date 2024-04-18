#ifndef QIMPROVEDSLIDER_H
#define QIMPROVEDSLIDER_H

#include <QSlider>

class QImprovedSlider : public QSlider
{
    Q_OBJECT
public:
    QImprovedSlider();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    explicit QImprovedSlider(QWidget *parent = nullptr);

signals:
    void clicked(int value);
};

#endif // QIMPROVEDSLIDER_H
