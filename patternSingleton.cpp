#include<iostream>
#include<string>
using namespace std;

class SettingsManager{
    public:
    static SettingsManager& getInstance(){
        static SettingsManager instance;
        return instance;
    };

    string mode = "light";

    void display(){
        cout << "Mode: "<< mode << endl;
    }

    SettingsManager(const SettingsManager&) = delete;
    void operator=(const SettingsManager&) = delete;

    private:
    SettingsManager(){
        mode = "ambient";
    };
};

int main(){
    cout <<"Singleton Sample code:" << endl;
    auto & settings = SettingsManager::getInstance();
    settings.display();
    settings.mode = "dark";
    settings.display();
}