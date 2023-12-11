#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum LogPriority {
    TraceP, DebugP, InfoP, WarnP, ErrorP, FatalP
};

class Log {
private:
    static LogPriority verbosity;
    static const char* filepath;

public:
    static void setVerbosity(LogPriority newPriority);
    static void l(LogPriority priority, const char* message);
    static void clearLog();
};

#endif // LOG_HPP