#include "QPatcherWindowsTrayIcon.h"
#include <qdesktopwidget.h>
#include <QWidget>
#include <QAction>
#include <QWidget>
#include <QMenu>

#include "GeneralCode/Function.h"
#include "GeneralCode/GlobalControl.h"

#include <windows.h>
#include <stdint.h>
#include <tlhelp32.h>

QPatcherWindowsTrayIcon::QPatcherWindowsTrayIcon()
{
}


QPatcherWindowsTrayIcon::~QPatcherWindowsTrayIcon()
{
    Function::DeletePointer<QAction>(m_Action_Quit);
    Function::DeletePointer<QAction>(m_Action_Reset);
    Function::DeletePointer<QMenu>(m_TrayMenu);
    Function::DeletePointer<QSystemTrayIcon>(m_Tray);
}

void QPatcherWindowsTrayIcon::PatchTo(QWidget* widget_toPatch)
{
    m_Widget = widget_toPatch;
    m_TrayMenu = new QMenu();
    m_Action_Reset = new QAction(this);
    m_Action_Reset->setText("show");
    connect(m_Action_Reset, &QAction::triggered, this, [this](){m_Widget->show(); });
    m_Action_Quit = new QAction(this);
    m_Action_Quit->setText("quit");
    connect(m_Action_Quit, &QAction::triggered, this, [this](){pGlobalController.QuitApplication(); });
    m_TrayMenu->addAction(m_Action_Reset);
    m_TrayMenu->addAction(m_Action_Quit);

    m_Tray = new QSystemTrayIcon(this);
    m_Tray->setIcon(QIcon("images/miku/0.png"));

    m_Tray->show();
    m_Tray->setContextMenu(m_TrayMenu);




#ifdef SystemIconActiveMessageTest
    connect(m_Tray, &QSystemTrayIcon::activated, this, &QPatcherWindowsTrayIcon::Slot_SystemIconTriggered);
#endif

}

#ifdef SystemIconActiveMessageTest
#pragma comment(linker, "/subsystem:console")
#include <iostream>
using namespace std;

void QPatcherWindowsTrayIcon::Slot_SystemIconTriggered(QSystemTrayIcon::ActivationReason _msg)
{
    switch (_msg)
    {
    case QSystemTrayIcon::Unknown:
        cout << "Unknown\n";
        break;
    case QSystemTrayIcon::Context:
        cout << "Context\n";
        break;
    case QSystemTrayIcon::DoubleClick:
        cout << "DoubleClick\n";
        break;
    case QSystemTrayIcon::Trigger:
        cout << "Trigger\n";
        break;
    case QSystemTrayIcon::MiddleClick:
        cout << "MiddleClick\n";
        break;
    default:
        cout << "default\n";
        break;
    }

}
#endif

