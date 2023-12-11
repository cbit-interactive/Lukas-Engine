#include "LoggingUtil.hpp"

using namespace std;

LogPriority Log::verbosity = TraceP;
const char* Log::filepath = "log.txt";

void Log::setVerbosity(LogPriority newPriority) {
    verbosity = newPriority;
}

static string getCurrentDateTime() {
    time_t rawTime;
    struct tm* timeInfo;
    char buffer[80];
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    return string(buffer);
}

void Log::l(LogPriority priority, const char* message) {
    if (priority >= verbosity){
            ofstream FILE(filepath, ios_base::app);
            FILE << getCurrentDateTime() << " - ";
            switch (priority){
                case TraceP: FILE << "Trace:\t"; break;
                case DebugP: FILE << "Debug:\t"; break;
                case InfoP: FILE << "Info:\t"; break;
                case WarnP: FILE << "Warning:\t"; break;
                case ErrorP: FILE << "ERROR IN [" << __FILE__ << "]:\t"; break;
                case FatalP: FILE << "fAtaL:\t"; break;
            }
            FILE << message << "\n";
            FILE.close();
        }
}

void Log::clearLog() {
    std::ofstream clearFile(filepath, std::ofstream::out | std::ofstream::trunc);
    clearFile.close();
}