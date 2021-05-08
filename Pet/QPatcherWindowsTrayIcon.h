#pragma once

#include <QObject>
#include <QSystemTrayIcon>

class QWidget;
class QMenu;
class QAction;

class QPatcherWindowsTrayIcon : public QObject
{
    Q_OBJECT

public:
    QPatcherWindowsTrayIcon();
    ~QPatcherWindowsTrayIcon();

    void PatchTo(QWidget* widget_toPatch);
    

private:
    QSystemTrayIcon* m_Tray = NULL;    //œµÕ≥Õ–≈ÃÕº±Í
    QMenu* m_TrayMenu = NULL;
    QAction* m_Action_Quit = NULL;
    QAction* m_Action_Reset = NULL;

    QWidget* m_Widget;

#ifdef SystemIconActiveMessageTest
    void Slot_SystemIconTriggered(QSystemTrayIcon::ActivationReason _msg);
#endif // #ifdef SystemIconActiveMessageTest

};

