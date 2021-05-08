#ifndef GLOBALCONTROLERCP_H
#define GLOBALCONTROLERCP_H

#include <mutex>
#include <atomic>
#include <QObject>
#include <windows.h>

#include "Define.h"
#include "ConnectionGenerator.h"

#define pGlobalController (*GlobalControl::GetInstance())


class QConnectionGlobal : public QObject
{
    Q_OBJECT

signals:


};

//一个供界面调用的汇总功能的单例类
//尽量减少直接操作函数，将封装好的manager指针传给调用者
//原则：尽可能只有一行
class GlobalControl
{
public:
    static GlobalControl* GetInstance();

    QConnectionGlobal m_QInterface;

    //CommonUseful

#pragma region SpecialUseful
    static void CreateApplicationMutex();
    static void QuitApplication();
    static void ReleaseApplicationMutexOnly();
#pragma endregion

private:
    void Initialize();

private:
    GlobalControl();
    ~GlobalControl();
    static GlobalControl* m_Instance;

    std::string m_Log;

#pragma region SpecialUseful
    static HANDLE m_ApplicationMutex;
#pragma endregion

};




#endif GLOBALCONTROLERCP_H
