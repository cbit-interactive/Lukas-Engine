#include "localisation.hpp"
#include "utils/LoggingUtil.hpp"
#include <fstream>

using namespace std;

unordered_map<string, string> Locale::translations;


void Locale::setLanguage(const string& langID){
    translations.clear();

    ifstream file("langs/" + langID + ".lang");

    if(!file.is_open()){
        Log::l(ErrorP, "Error! Could not open language file for settings defined language!");
        return;
    }

    string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            translations[key] = value;
        }
    }

}

string Locale::getS(const string& key){
    auto it = translations.find(key);
    return (it != translations.end()) ? it->second : key; // Return the key if the key itself is not found
}