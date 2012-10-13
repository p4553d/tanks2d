/**
 * @file Log.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _LOG_H
#define _LOG_H

#include <pthread.h>
#include <stdio.h>
#include <errno.h>

//must be put in global scope and used once in all files
#define LOG_DECLARE Log _sgLog;


//init log files, called once in program initialization
#define LOG_INIT(fileName); _sgLog.init(fileName);

//here are the different levels of logging
#define LOG_INFO(msg) _sgLog.write("info", msg, __FILE__, __LINE__); //detaild info
#define LOG_MSG(msg) _sgLog.write("mesg", msg, __FILE__, __LINE__); //brief info
#define LOG_WARN(msg) _sgLog.write("warn", msg, __FILE__, __LINE__); //warning
#define LOG_ERR(msg) _sgLog.write("error", msg, __FILE__, __LINE__); //error
#define LOG_FATAL(msg) _sgLog.write("fatal", msg, __FILE__, __LINE__); //fatal error


class Log {
private:
    FILE * fp;
    bool logOk;

public:
    Log();
    ~Log();

    void init(const char * pfileName);
    void close();
    void write(const char * pType, const char * pMsg, const char * pFileName, const int lineNo);

    pthread_mutex_t log_mutex;
};

extern Log _sgLog;

#endif
