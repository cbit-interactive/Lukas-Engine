#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <unordered_map>
#include <string>

using namespace std;

class SettingsReader {
    public:
        SettingsReader(const string& filePath);

        int getSetting(const string& key) const;

    private:
        unordered_map<string, int> settings;
};

#endif