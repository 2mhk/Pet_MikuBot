#include "Pet.h"
#include <QtWidgets/QApplication>
#include <QDir>

#include "GeneralCode/GlobalControl.h"
#include <windows.h>

#include <DbgHelp.h>
#pragma comment(lib,"Dbghelp.lib")
long __stdcall CrashInfocallback(_EXCEPTION_POINTERS *pexcp)
{
    //创建 Dump 文件
    HANDLE hDumpFile = ::CreateFile(
        L"dumpfile.dmp",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        );
    if (hDumpFile != INVALID_HANDLE_VALUE)
    {
        //Dump信息
        MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
        dumpInfo.ExceptionPointers = pexcp;
        dumpInfo.ThreadId = GetCurrentThreadId();
        dumpInfo.ClientPointers = TRUE;
        //写入Dump文件内容
        ::MiniDumpWriteDump(
            GetCurrentProcess(),
            GetCurrentProcessId(),
            hDumpFile,
            MiniDumpNormal,
            &dumpInfo,
            NULL,
            NULL
            );
    }
    return 0;
}


int main(int argc, char *argv[])
{
    GlobalControl::CreateApplicationMutex();    //不要在qt初始化完后再运行，否则概率崩溃

    QApplication a(argc, argv);

    //Windows开机启动的程序工作目录会切到system32里去.
    //因此此程序中单例模式禁止使用饿汉模式,且对文件的使用及初始化必须要在切完目录后进行操作!!
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QApplication::addLibraryPath("plugins");    //release需要

    ::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)CrashInfocallback);     //dumpFile


    Pet w;
    w.show();

    return a.exec();
}
