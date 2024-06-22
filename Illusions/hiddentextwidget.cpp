#include "hiddentextwidget.h"

HiddenTextWidget::HiddenTextWidget(QString questionText, QString hiddenText) : QWidget()
{
    layout = new QVBoxLayout(this);

    stackedWidget = new QStackedWidget;

    //font setup
    IllusionSS *ss = new IllusionSS();
    QFont explanationFont = ss->ChaletBook_Regular;
    QFont questionFont = ss->ChaletBook_Bold;
    QFont buttonFont = ss->ChaletBook_Oblique;

    //question label
    question = new QLabel(questionText);
    question->setAlignment(Qt::AlignLeft);
    question->setWordWrap(true);
    questionFont.setPixelSize(40);
    question->setFont(questionFont);
    layout->addWidget(question);
    layout->addSpacing(10);

    //initially visible widget setup
    visibleWidget = new QWidget(this);
    visibleLayout = new QVBoxLayout(visibleWidget);
    visibleLayout->setAlignment(Qt::AlignHCenter);

    //button
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);
    buttonLayout->setAlignment(Qt::AlignHCenter);
    revealTextButton = new QPushButton();
    buttonFont.setPixelSize(30);
    revealTextButton->setFont(buttonFont);
    revealTextButton->setStyleSheet(ss->hiddenTextButtonStyle);
    buttonLayout->addWidget(revealTextButton);
    visibleLayout->addWidget(buttonWidget);

    //touch to reveal label
    revealLabel = new QLabel("Touch to reveal explanation!");
    revealLabel->setWordWrap(false);
    revealLabel->setAlignment(Qt::AlignHCenter);
    questionFont.setPixelSize(40);
    revealLabel->setFont(buttonFont);
    visibleLayout->addWidget(revealLabel);
    stackedWidget->addWidget(visibleWidget);

    //hidden text
    text = new QLabel(hiddenText);
    text->setAlignment(Qt::AlignLeft);
    text->setWordWrap(true);
    explanationFont.setPixelSize(30);
    text->setFont(explanationFont);
    stackedWidget->addWidget(text);

    stackedWidget->setCurrentIndex(0);
    connect(revealTextButton, SIGNAL(clicked()), this, SLOT(revealText()));

    layout->addWidget(stackedWidget, Qt::AlignCenter);
}

void HiddenTextWidget::setText(QString newQuestionText, QString newHiddenText) {
    question->setText(newQuestionText);
    text->setText(newHiddenText);
}

void HiddenTextWidget::revealText() {
    emit textRevealed();
    stackedWidget->setCurrentIndex(1);
}

void HiddenTextWidget::hideText() {
    stackedWidget->setCurrentIndex(0);
}
