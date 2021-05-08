#include "GlobalControl.h"
#include "ConnectionGenerator.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <windows.h>

GlobalControl* GlobalControl::m_Instance = NULL;
HANDLE GlobalControl::m_ApplicationMutex = NULL;

GlobalControl::GlobalControl()
{
    Initialize();

    pConnectionGenerator.Set_GlobalControl(this);
}

GlobalControl::~GlobalControl()
{
    ReleaseApplicationMutexOnly();
}



GlobalControl* GlobalControl::GetInstance()
{
    if (m_Instance == NULL)
    {
        static std::mutex m_mutex;
        MutexGuard(m_mutex);
        if (m_Instance == NULL)
        {
            GlobalControl* ptmp = new GlobalControl();
            m_Instance = ptmp;
        }
    }
    return m_Instance;
}

void GlobalControl::Initialize()
{

}

void GlobalControl::CreateApplicationMutex()
{
    m_ApplicationMutex = CreateMutex(NULL, TRUE, L"{BEATRICE-E48C-4bJ9-A9DH-CFKDX4CKF9A3}");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        if (m_ApplicationMutex)
            CloseHandle(m_ApplicationMutex);
        exit(0);
    }
}

void GlobalControl::QuitApplication()
{
    try
    {
        ReleaseApplicationMutexOnly();
        qApp->quit();
    }
    catch (...)
    {
    }
}


void GlobalControl::ReleaseApplicationMutexOnly()
{
    if (m_ApplicationMutex)
    {
        try
        {
            ReleaseMutex(m_ApplicationMutex);
            CloseHandle(m_ApplicationMutex);
        }
        catch (...)
        {
        }
    }
}

