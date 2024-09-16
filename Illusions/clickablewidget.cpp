#include "clickablewidget.h"

/**
 * @author Joseph Daprano <joseph.daprano@gmail.com>
 *
 * The ClickableWidget class represents a widget that emits a signal whenever it gets clicked
 */

ClickableWidget::ClickableWidget() : QWidget()
{}

/*
 * Override unction to filter clicks that should emit the clicked signal
 *
 * Arguments: QMouseEvent* - mouse event pointer to filter
 * Returns: void
 */
void ClickableWidget::mousePressEvent(QMouseEvent *event) {
    emit clicked();
    QWidget::mousePressEvent(event);
}

/*
 * Function to filter paint events that should draw ClickedWidget rather than Widget
 *
 * Arguments: QPaintEvent* - paint event pointer to filter
 * Returns: void
 */
void ClickableWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
