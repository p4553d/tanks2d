/**
 * @file Log.cpp
 * @author user p4553d
 */


#include "Log.h"

Log::Log() {
    fp = NULL;
}

Log::~Log() {
    close();
}

void Log::init(const char * pfileName) {
    pthread_mutex_init (&log_mutex, NULL);
    if(pfileName != NULL) {
        fp = fopen(pfileName, "a+");
        if(fp != NULL) {
            fseek(fp, 0, SEEK_END);
        } else {
            fprintf(stderr, "Can not open file for log! rc=%d\n", errno);
            fp=stderr;
        }
    } else {
        fp=stderr;
    }
}

void Log::close() {
    if(fp != NULL && fp != stderr) {
        fclose(fp);
    }
    fp = NULL;
}

void Log::write(const char * pType, const char * pMsg, const char * pFileName, const int lineNo) {
    if(fp != NULL) {
        pthread_mutex_lock(&log_mutex);
        fprintf(fp, "%s|%s %s|%s:%d\t%s\n", pType, __DATE__, __TIME__, pFileName, lineNo, pMsg);
        fflush(fp);
        pthread_mutex_unlock(&log_mutex);
    }
}
