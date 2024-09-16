#include "widgetbutton.h"
/**
 * @author Joseph Daprano <joseph.daprano@gmail.com>
 *
 * The WidgetButton class subclasses the QToolButton class to associate a specific QWidget* with a button
 */

WidgetButton::WidgetButton(QWidget *_widget, QString _iconPath) : QToolButton()
{
    this->widget = _widget;
    this->iconPath = _iconPath;

    //If icon path is a valid image, set the button icon to that image
    if(!QImageReader::imageFormat(iconPath).isNull()) {
        this->setIcon(QIcon(iconPath));
    } else { //If not a valid image path, set button icon to text of file basename
        this->setText(QFileInfo(iconPath).baseName());
    }
    connect(this, SIGNAL(clicked()), this, SLOT(emitClickedSignal()));
}

/*
 * Slot function to emit clicked signal containing member widget on click
 *
 * Arguments: none
 * Returns: void
 */
void WidgetButton::emitClickedSignal()
{
    emit buttonClicked(this->widget);
}

/*
 * Function to return button's widget
 *
 * Arguments: none
 * Returns: QWidget* - pointer to button's widget
 */
QWidget* WidgetButton::getWidget()
{
    return this->widget;
}

/*
 * Function to return button's icon's filepath
 *
 * Arguments: none
 * Returns: QString - icon's filepath
 */
QString WidgetButton::getIconPath() {
    return this->iconPath;
}
