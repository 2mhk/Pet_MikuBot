#include "QSiderBar.h"

#include <iostream>


QSiderBar::QSiderBar(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    Initialize();
}

QSiderBar::~QSiderBar()
{

}

void QSiderBar::Initialize()
{
    m_AnimationPatcher_ShowSlide.PatchTo(this);
}

void QSiderBar::resizeEvent(QResizeEvent* event)
{
    m_AnimationPatcher_ShowSlide.resizeEvent(event);
    QWidget::resizeEvent(event);
}

