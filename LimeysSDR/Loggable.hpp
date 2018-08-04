//
//  Loggable.hpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef Loggable_hpp
#define Loggable_hpp

#include <cstdio>
#include <iostream>

#include "Util.hpp"

namespace io {
namespace github {
namespace paulyc {

// WARNING: Not currently thread-safe!
class Loggable
{
public:
    enum Level { Trace=0, Debug, Info, Warning, Error, Critical };
    static constexpr Level DefaultLevel = Debug;
    
    Loggable() : _currentLevel(DefaultLevel), _prefix(nullptr), _cLogStream(stdout), _streamLogger(std::cout) {}
    Loggable(const char *prefix) : Loggable() { _prefix = prefix; }
    virtual ~Loggable() {}
    
    Level GetCurrentLogLevel() const { return _currentLevel; }
    void SetCurrentLogLevel(Level l) { _currentLevel = l; }
    
protected:
    int Log(Level l, const char *fmtStr, ...);
    int LogTimestamp(Level l, const char *logMsg);
    
    // Not thread safe particularly with re: to log level being enabled
    std::string FormatLogPrefix(Level l);
    
    template <typename Stream_T>
    class StreamLogger
    {
    public:
        StreamLogger(Stream_T &logStream) : _enabled(true), _logStream(logStream) {}
        
        template <typename T>
        StreamLogger<Stream_T> &operator<<(const T &rhs) {
            if (_enabled) {
                _logStream << rhs;
            }
            return *this;
        }
        
        void SetEnabled(bool enabled) { _enabled = enabled; }
    private:
        bool _enabled;
        Stream_T &_logStream;
    };
    typedef StreamLogger<std::ostream> DefaultStreamLogger;
    
    FILE *GetCurrentCLogStream() const {
        return _cLogStream;
    }
    
    DefaultStreamLogger &LogStream(Level l=Info) {
        if (l >= _currentLevel) {
            _streamLogger.SetEnabled(true);
            _streamLogger << FormatLogPrefix(l) << ' ';
        } else {
            _streamLogger.SetEnabled(false);
        }
        return _streamLogger;
    }
private:
    static const char * LevelStrings[];
    static constexpr const char * LogFmtStr = "[%s] [%s] %s";
    static constexpr const char * LogFmtStrPrefix = "[%s] [%s] [%s] %s\n";
    static constexpr const char * LogFmtNoPrefix = "[%s] [%s]";
    static constexpr const char * LogFmtPrefix = "[%s] [%s] [%s]";
    static constexpr const char * LogFmtPrefixStr = "%s %s\n";
    
    Level _currentLevel;
    const char *_prefix;
    
    FILE *_cLogStream;
    DefaultStreamLogger _streamLogger;
};

}
}
}

#endif /* Loggable_hpp */
