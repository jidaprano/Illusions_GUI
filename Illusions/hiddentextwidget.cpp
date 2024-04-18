#include "hiddentextwidget.h"

HiddenTextWidget::HiddenTextWidget(QString hiddenText) : QWidget()
{
    layout = new QVBoxLayout(this);

    stackedWidget = new QStackedWidget;

    revealTextButton = new QPushButton("Click to reveal explanation!");
    stackedWidget->addWidget(revealTextButton);

    //font setup
    IllusionSS *ss = new IllusionSS();
    QFont explanationFont = ss->ChaletBook_Regular;

    text = new QLabel(hiddenText);
    text->setAlignment(Qt::AlignLeft);
    text->setWordWrap(true);
    explanationFont.setPixelSize(36);
    text->setFont(explanationFont);
    stackedWidget->addWidget(text);

    stackedWidget->setCurrentIndex(0);
    connect(revealTextButton, SIGNAL(clicked()), this, SLOT(revealText()));

    layout->addWidget(stackedWidget, Qt::AlignCenter);
}

void HiddenTextWidget::setText(QString newText) {
    text->setText(newText);
}

void HiddenTextWidget::revealText() {
    stackedWidget->setCurrentIndex(1);
}

void HiddenTextWidget::hideText() {
    stackedWidget->setCurrentIndex(0);
}
