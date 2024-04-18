#include "qimprovedslider.h"
#include <QProxyStyle>
#include <QStyleOptionSlider>
#include <QMouseEvent>

class DirectJump : public QProxyStyle
{
public:
    using QProxyStyle::QProxyStyle;
    int styleHint(QStyle::StyleHint hint, const QStyleOption* option = 0,
                  const QWidget* widget = 0, QStyleHintReturn* returnData = 0) const
    {
        if (hint == SH_Slider_AbsoluteSetButtons)
            return (Qt::LeftButton);
        return QProxyStyle::styleHint(hint, option, widget, returnData);
    }

};

QImprovedSlider::QImprovedSlider(QWidget *parent) : QSlider(parent)
{
    setStyle(new DirectJump);
}

void QImprovedSlider::mousePressEvent(QMouseEvent *event) {
    QStyleOptionSlider opt;
    initStyleOption(&opt);
    QRect sr = style()->subControlRect(QStyle::CC_Slider,
                                       &opt,
                                       QStyle::SC_SliderHandle,
                                       this);
    if (event->button() == Qt::LeftButton &&
        !sr.contains(event->pos())) {
        int newVal;
        if (orientation() == Qt::Vertical) {
            double halfHandleHeight = (0.5 * sr.height()) + 0.5;
            int adaptedPosY = height() - event->y();
            if (adaptedPosY < halfHandleHeight) {
                adaptedPosY = halfHandleHeight;
            }
            if (adaptedPosY > height() - halfHandleHeight) {
                adaptedPosY = height() - halfHandleHeight;
            }
            double newHeight = (height() - halfHandleHeight) - halfHandleHeight;
            double normalizedPosition = (adaptedPosY - halfHandleHeight)  / newHeight ;
            newVal = minimum() + (maximum()-minimum()) * normalizedPosition;
        }
        else {
            double halfHandleWidth = (0.5 * sr.width());
            int adaptedPosX = event->x();
            if (adaptedPosX < halfHandleWidth) {
                adaptedPosX = halfHandleWidth;
            }
            if (adaptedPosX > width() - halfHandleWidth) {
                adaptedPosX = width() - halfHandleWidth;
            }
            double newWidth = (width() - halfHandleWidth) - halfHandleWidth;
            double normalizedPosition = (adaptedPosX - halfHandleWidth)  / newWidth ;
            newVal = minimum() + ((maximum()-minimum()) * normalizedPosition);
        }
        if (invertedAppearance() == true) {
            this->setValue( maximum() - newVal );
        }
        else {
            this->setValue(newVal);
        }
    }
    QSlider::mousePressEvent(event);
}

void QImprovedSlider::mouseReleaseEvent(QMouseEvent *event) {
    if (isSliderDown()) {
        emit clicked(value());
    }

    QSlider::mouseReleaseEvent(event);
}
