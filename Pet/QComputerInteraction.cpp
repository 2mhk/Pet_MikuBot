#include "QComputerInteraction.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMouseEvent>
#include "GeneralCode/Function.h"

#include "windows.h"

QComputerInteraction::QComputerInteraction()
{
    Initialize();
}

QComputerInteraction::~QComputerInteraction()
{
    Function::DeletePointer<QMouseSimulation>(m_MouseSimulation);
}

void QComputerInteraction::Initialize()
{
    m_MouseSimulation = new QMouseSimulation();

}

void QComputerInteraction::Click()
{
    //QDesktopWidget* desktopWidget = QApplication::desktop();
    //QMouseEvent pressEvent(QEvent::MouseButtonPress, m_MouseSimulation->pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    //QMouseEvent releaseEvent(QEvent::MouseButtonRelease, m_MouseSimulation->pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    //QApplication::sendEvent(desktopWidget, &pressEvent);
    //QApplication::sendEvent(desktopWidget, &releaseEvent);
    //mouse_event(MOUSEEVENTF_LEFTDOWN, m_MouseSimulation->x(), m_MouseSimulation->y(), 0, 0);
    //mouse_event(MOUSEEVENTF_LEFTUP, m_MouseSimulation->x(), m_MouseSimulation->y(), 0, 0);

    //INPUT input[4];
    //memset(input, 0, sizeof(input));
    //input[0].type = input[1].type = input[2].type = input[3].type = INPUT_KEYBOARD;
    //input[0].ki.wVk = input[3].ki.wVk = VK_LWIN;
    //input[1].ki.wVk = input[2].ki.wVk = 'D';
    //input[2].ki.dwFlags = input[3].ki.dwFlags = KEYEVENTF_KEYUP;
    //SendInput(4, input, sizeof(INPUT));


    QPoint _point = m_MouseSimulation->pos();

    SetCursorPos(m_MouseSimulation->x() + 13, m_MouseSimulation->y() + 5);
    INPUT m_InPut[2] = { 0 };
    //鼠标消息，需将type置为INPUT_MOUSE，如果是键盘消息,将type置为INPUT_KEYBOARD。
    m_InPut[0].type = m_InPut[1].type = INPUT_MOUSE;
    //将type置为鼠标消息后，其INPUT结构中的mi结构是可以使用的，hi、ki结构不可使用
    m_InPut[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    m_InPut[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(sizeof(m_InPut) / sizeof(m_InPut[0]), m_InPut, sizeof(INPUT));



    m_MouseSimulation->ShowFlash(50);
}
