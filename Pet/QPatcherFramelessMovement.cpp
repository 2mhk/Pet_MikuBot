#include "QPatcherFramelessMovement.h"

#include <QMouseEvent>
#include <QWidget>

#include "GeneralCode/Function.h"

QPatcherFramelessMovement::QPatcherFramelessMovement()
{
    m_isMoving = false;
}


QPatcherFramelessMovement::~QPatcherFramelessMovement()
{
}

void QPatcherFramelessMovement::PatchTo(QWidget* widget_toPatch)
{
    m_Widget = widget_toPatch;
}

void QPatcherFramelessMovement::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isMoving = true;
        m_StartPoint = event->globalPos();
        m_WindowPoint = m_Widget->frameGeometry().topLeft();
        //QPoint slPos = event->pos();
    }
}
void QPatcherFramelessMovement::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton && m_isMoving)
    {
        QPoint relativePos = event->globalPos() - m_StartPoint;
        m_Widget->move(m_WindowPoint + relativePos);
    }
}
void QPatcherFramelessMovement::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isMoving = false;
    }
}
