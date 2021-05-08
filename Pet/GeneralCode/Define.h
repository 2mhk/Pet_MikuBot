/********************************************************************************
*
*	Description		定义文件，内部包含一些对程序的全局定义
*	Version			1.0.1
*	Author			Sherlock
*	Creation Time	2018/8/1	1.0.1
*	Modify
*
*******************************************************************************/

#ifndef _DEFINE_H_
#define _DEFINE_H_

#include <QDate>
#include <QTime>
#include <QLocale>
#include <QMetaType>
#include <QTextCodec>

//使能
#define ENABLE_LOG_HEARTBREAK_Qt        0       //心跳Log - Qt
#define ENABLE_LOG_HEARTBREAK_cout      1       //心跳Log - cout

static const std::string VERSION = "0.0.1";

static const QDate BUILD_DATE = QLocale(QLocale::English).toDate(QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy");
static const QTime BUILD_TIME = QTime::fromString(__TIME__, "hh:mm:ss");

static const QString PROJECT_NAME = QTextCodec::codecForLocale()->toUnicode("Project Name Space");

#define FILENAME_SETTINGS_JSON "Config/Setting.json"

//Q_DECLARE_METATYPE(cv::Mat);

//Code只在第一次调用是生效
#define ProcessOnlyFirstTime(Code)\
    {\
        static bool isFirst = true;\
        if (isFirst)\
                {\
            isFirst = false;\
            Code\
                }\
    }


#define ENABLE_PRINT_TIME_STAMP 1

#if ENABLE_PRINT_TIME_STAMP
#define PrintCurrentTime(TimeStamp)\
    {\
        time_t TimeStamp = clock();\
        std::cout << #TimeStamp << " : "<< TimeStamp << " ms " << __FUNCDNAME__ << endl;\
    }
#else
#define PrintCurrentTime(TimeStamp)
#endif

#define SetMutex \
    static std::mutex _TmpMutex_SetMutex;\
    std::lock_guard<std::mutex> guard(_TmpMutex_SetMutex);

#define MutexGuard(_mutex) std::lock_guard<std::mutex> _LockGuard_MutexGuard(_mutex);

#if ENABLE_LOG_HEARTBREAK_Qt
#define LogHeartBreak qInfo() << "function: " << __FILE__ << " line:" << __LINE__;
#else
//#define LogHeartBreak
#endif

#if ENABLE_LOG_HEARTBREAK_cout
#define LogHeartBreak cout << "function: " << __FILE__ << " line:" << __LINE__;
#define LogHeartBreak_Addon(_else) cout << "function: " << __FILE__ << " line:" << __LINE__ << _else;
//#define LogHeartBreak(...) cout << "function: " << __FILE__ << " line:" << __LINE__ << __VA_ARGS__;
#else
//#define LogHeartBreak
#endif

#if 0       //For Quick Debug
#pragma comment(linker, "/subsystem:console")
#include <iostream>
using namespace std;
#endif

#endif	_DEFINE_H_
