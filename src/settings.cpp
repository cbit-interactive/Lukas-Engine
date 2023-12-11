#include "settings.hpp"
#include "utils/LoggingUtil.hpp"
#include <iostream>
#include <fstream>

using namespace std;

SettingsReader::SettingsReader(const string& filePath){
    ifstream inputFile(filePath);

    if(!inputFile.is_open()){
        Log::l(ErrorP, "Unable to open settings file.");
        return;
    }
    string line;
    while(getline(inputFile, line)){
        size_t delimiterPos = line.find('=');
        if (delimiterPos != string::npos){
            string key = line.substr(0, delimiterPos);
            string valueStr = line.substr(delimiterPos + 1);

            try {
                int value = stoi(valueStr);
                settings[key] = value;
            } catch(const invalid_argument& e){
                Log::l(ErrorP, "Invalid value for key");
            } catch(out_of_range& e){
                Log::l(ErrorP, "Value out of range for key");
            }
        }
    }
}

int SettingsReader::getSetting(const string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()){
        return it->second;
    } else {
        Log::l(ErrorP, "Key not found in settings!");
        return 0;
    }
}