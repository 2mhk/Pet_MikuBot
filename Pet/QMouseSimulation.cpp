#include "QMouseSimulation.h"
#include <QTimer>

QMouseSimulation::QMouseSimulation(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    Initialize();
}

QMouseSimulation::~QMouseSimulation()
{

}

void QMouseSimulation::Initialize()
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    show();
    m_PatcherMovement.PatchTo(this);
}

void QMouseSimulation::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    m_PatcherMovement.mousePressEvent(event);
}

void QMouseSimulation::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
    m_PatcherMovement.mouseMoveEvent(event);
}

void QMouseSimulation::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
    m_PatcherMovement.mouseReleaseEvent(event);
}

void QMouseSimulation::ShowFlash(int _microSeconds)
{
    const int delayMicroSec = 0;
    show();
    //QTimer::singleShot(50, [this](){hide(); });
    //QTimer::singleShot(_microSeconds+50, [this](){show(); });
    QTimer::singleShot(delayMicroSec, [this](){ui.label->setPixmap(QPixmap(":/images/action/pointer_white.png")); });
    QTimer::singleShot(_microSeconds + delayMicroSec, [this](){ui.label->setPixmap(QPixmap(":/images/action/pointer_black.png")); });
}
