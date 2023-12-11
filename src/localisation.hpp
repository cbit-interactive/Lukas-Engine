#ifndef LOCALISATION_HPP
#define LOCALISATION_HPP

#include <unordered_map>
#include <string>

using namespace std;

class Locale {
    public:
        static void setLanguage(const string& langID);
        static string getS(const string& key);
    private:
        static unordered_map<string, string> translations;
};

#endif