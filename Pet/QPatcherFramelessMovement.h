#pragma once

#include <QPoint>

class QWidget;
class QMouseEvent;

class QPatcherFramelessMovement
{
public:
    QPatcherFramelessMovement();
    ~QPatcherFramelessMovement();

    bool m_isMoving;
    QPoint m_StartPoint;
    QPoint m_WindowPoint;
    QWidget* m_Widget = nullptr;

    void PatchTo(QWidget* widget_toPatch);

    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
     
    void mouseReleaseEvent(QMouseEvent* event);

};

