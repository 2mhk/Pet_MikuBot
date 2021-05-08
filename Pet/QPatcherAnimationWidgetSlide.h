#pragma once

#include <QObject>
#include <QPropertyAnimation>
#include <QPoint>

class QWidget;
class QResizeEvent;

class QPatcherAnimationWidgetSlide : public QObject
{
    Q_OBJECT
public:
    QPatcherAnimationWidgetSlide();
    ~QPatcherAnimationWidgetSlide();

    void PatchTo(QWidget* widget_toPatch);
    
    //use
    void Show_AnimationSlide(bool isForced = false);
    void Hide_AnimationSlide(bool isForced = false);

    //protected requst
    void resizeEvent(QResizeEvent* event);

    bool m_isVisible = true;

private:
    QWidget* m_Widget = NULL;

    QPropertyAnimation m_Animation_Show;
    QPropertyAnimation m_Animation_Hide;
    int m_Interval_microscond = 300;
    void AnimationInitialize_Show();
    void AnimationInitialize_Hide();
    QPoint m_PointShow;
    QPoint m_PointHide;
};

