#include "QPatcherAnimationWidgetSlide.h"
#include <QWidget>
#include <thread>
#include <time.h>

QPatcherAnimationWidgetSlide::QPatcherAnimationWidgetSlide()
{
}


QPatcherAnimationWidgetSlide::~QPatcherAnimationWidgetSlide()
{
}

void QPatcherAnimationWidgetSlide::PatchTo(QWidget* widget_toPatch)
{
    m_Widget = widget_toPatch;
    AnimationInitialize_Show();
    AnimationInitialize_Hide();
}

void QPatcherAnimationWidgetSlide::Show_AnimationSlide(bool isForced)
{
    if (!isForced && m_Widget->isVisible())
        return;
    if (!m_Widget->isVisible())
    {
        m_Widget->show();
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));     //实测hide状态下Animation无法显示且有些许延迟
    }

    m_Animation_Show.start();
    m_isVisible = true;
}

void QPatcherAnimationWidgetSlide::AnimationInitialize_Show()
{
    m_Animation_Show.setTargetObject(m_Widget);
    m_Animation_Show.setPropertyName("pos");
    m_Animation_Show.setDuration(m_Interval_microscond);
}

void QPatcherAnimationWidgetSlide::Hide_AnimationSlide(bool isForced)
{
    if (!isForced && !m_Widget->isVisible())
        return;

    m_Animation_Hide.start();
    m_isVisible = false;
}

void QPatcherAnimationWidgetSlide::AnimationInitialize_Hide()
{
    m_Animation_Hide.setTargetObject(m_Widget);
    m_Animation_Hide.setPropertyName("pos");
    m_Animation_Hide.setDuration(m_Interval_microscond);
}

void QPatcherAnimationWidgetSlide::resizeEvent(QResizeEvent* event)
{
    m_PointShow = QPoint(m_Widget->pos().x(), m_Widget->pos().y());
    m_PointHide = QPoint(m_Widget->pos().x(), m_Widget->pos().y() - m_Widget->height());

    m_Animation_Show.setStartValue(m_PointHide);
    m_Animation_Show.setEndValue(m_PointShow);

    m_Animation_Hide.setStartValue(m_PointShow);
    m_Animation_Hide.setEndValue(m_PointHide);
}


