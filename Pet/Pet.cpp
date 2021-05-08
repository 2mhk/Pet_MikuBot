#include "Pet.h"

#include <QPropertyAnimation>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>

#include "GeneralCode/Function.h"
#include "ResourcePlaceholder.h"
#include "QComputerInteraction.h"
#include "GeneralCode/GlobalControl.h"

using namespace std;
#include <iostream>

Pet::Pet(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    Initialize();
}

Pet::~Pet()
{
    Function::DeletePointer<QTimer>(m_Timer_DropButton);
    Function::DeletePointer<QComputerInteraction>(m_ComputerInteraction);
}

void Pet::Initialize()
{
    m_Patcher_WidgetMovement.PatchTo(this);
    m_Patcher_LabelImageAnime.PatchTo(ui.label);
    m_Patcher_WindowsTrayIcon.PatchTo(this);

    m_ComputerInteraction = new QComputerInteraction();
    connect(ui.widget_buttonBar->ui.pushButton_human, &QPushButton::clicked, this, [this](){m_ComputerInteraction->Click(); });

    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    
    //ui.label->setPixmap(QPixmap("images/miku/0.png"));

    QDesktopWidget* desktopWidget = QApplication::desktop();
    move(desktopWidget->width() - width() - 60, desktopWidget->height() - height() - 60);

    connect(ui.widget_buttonBar->ui.pushButton_exit, &QPushButton::clicked, this, [this](){pGlobalController.QuitApplication(); });

    ui.label->installEventFilter(this);
}

void Pet::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    m_Patcher_WidgetMovement.mousePressEvent(event);

}

void Pet::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    m_Patcher_WidgetMovement.mouseMoveEvent(event);

}

void Pet::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    m_Patcher_WidgetMovement.mouseReleaseEvent(event);
}

bool Pet::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui.label)
    {
        switch (event->type())
        {
        case QEvent::MouseButtonPress:
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->buttons() == Qt::RightButton)
            {
                if (ui.widget_buttonBar->m_AnimationPatcher_ShowSlide.m_isVisible)
                    ui.widget_buttonBar->m_AnimationPatcher_ShowSlide.Hide_AnimationSlide(true);
                else
                    ui.widget_buttonBar->m_AnimationPatcher_ShowSlide.Show_AnimationSlide(true);
            }
            break;
        }
        default:
            break;
        }
    } 

    return QWidget::eventFilter(object, event);
}
