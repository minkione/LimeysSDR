//
//  Loggable.cpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#include "Loggable.hpp"

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>

namespace io {
namespace github {
namespace paulyc {
            
const char * Loggable::LevelStrings[] = { "TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL" };

    int Loggable::Log(Level l, const char *fmtStr, ...)
    {
        if (l >= _currentLevel) {
            char logMsg[4096];
            
            va_list args;
            va_start(args, fmtStr);
            vsnprintf(logMsg, sizeof(logMsg), fmtStr, args);
            va_end(args);
            return LogTimestamp(l, logMsg);
        } else {
            return 0;
        }
    }
    
    std::string Loggable::FormatLogPrefix(Level l) {
        char logFmt[4096];
        char timeFmt[1024];
        time_t ctm = time(nullptr);
        struct tm *timeinfo = gmtime(&ctm);
        strftime(timeFmt, sizeof(timeFmt), "%F %T %Z", timeinfo);
        if (_prefix == nullptr) {
            ::snprintf(logFmt, sizeof(logFmt), LogFmtNoPrefix, LevelStrings[l], timeFmt);
        } else {
            ::snprintf(logFmt, sizeof(logFmt), LogFmtPrefix, LevelStrings[l], _prefix, timeFmt);
        }
        return std::string(logFmt);
    }
    
    int Loggable::LogTimestamp(Level l, const char *logMsg) {
        std::string prefix = FormatLogPrefix(l);
        return ::fprintf(_cLogStream, LogFmtPrefixStr, prefix.c_str(), logMsg);
    }
    
}
}
}
