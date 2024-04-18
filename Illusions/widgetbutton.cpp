#include "widgetbutton.h"

WidgetButton::WidgetButton(QWidget *_widget, QString _iconPath) : QToolButton()
{
    this->widget = _widget;
    this->iconPath = _iconPath;
    if(!QImageReader::imageFormat(iconPath).isNull()) {
        this->setIcon(QIcon(iconPath));
    } else {
        this->setText(QFileInfo(iconPath).baseName());
    }
    connect(this, SIGNAL(clicked()), this, SLOT(emitClickedSignal()));
}

void WidgetButton::emitClickedSignal()
{
    emit buttonClicked(this->widget);
}

QWidget* WidgetButton::getWidget()
{
    return this->widget;
}

QString WidgetButton::getIconPath() {
    return this->iconPath;
}
