#include "Pet.h"
#include <QtWidgets/QApplication>
#include <QDir>

#include "GeneralCode/GlobalControl.h"
#include <windows.h>

#include <DbgHelp.h>
#pragma comment(lib,"Dbghelp.lib")
long __stdcall CrashInfocallback(_EXCEPTION_POINTERS *pexcp)
{
    //���� Dump �ļ�
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
        //Dump��Ϣ
        MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
        dumpInfo.ExceptionPointers = pexcp;
        dumpInfo.ThreadId = GetCurrentThreadId();
        dumpInfo.ClientPointers = TRUE;
        //д��Dump�ļ�����
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
    GlobalControl::CreateApplicationMutex();    //��Ҫ��qt��ʼ����������У�������ʱ���

    QApplication a(argc, argv);

    //Windows���������ĳ�����Ŀ¼���е�system32��ȥ.
    //��˴˳����е���ģʽ��ֹʹ�ö���ģʽ,�Ҷ��ļ���ʹ�ü���ʼ������Ҫ������Ŀ¼����в���!!
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QApplication::addLibraryPath("plugins");    //release��Ҫ

    ::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)CrashInfocallback);     //dumpFile


    Pet w;
    w.show();

    return a.exec();
}
