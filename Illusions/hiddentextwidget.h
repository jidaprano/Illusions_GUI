#ifndef HIDDENTEXTWIDGET_H
#define HIDDENTEXTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include "illusionss.h"

class HiddenTextWidget : public QWidget
{
    Q_OBJECT
public:
    HiddenTextWidget(QString hiddenText);
    void setText(QString newText);
private:
    QVBoxLayout *layout;
    QPushButton *revealTextButton;
    QStackedWidget *stackedWidget;
    QLabel *text;
public slots:
    void revealText();
    void hideText();
};

#endif // HIDDENTEXTWIDGET_H
