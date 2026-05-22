#include <iostream>
#include <string>

class SettingManager {
public:
    // 1. Public method to get the single instance
    static SettingManager& getInstance() {
        static SettingManager instance; // Created once, reused every time
        return instance;
    }

    // 2. Delete copy constructor and assignment operator to prevent duplicates
    SettingManager(const SettingManager&) = delete;
    void operator=(const SettingManager&) = delete;

    // Example member variables and methods
    std::string theme = "Light Mode";
    void displayTheme() {
        std::cout << "Current Theme: " << theme << "\n";
    }

private:
    // 3. Private constructor prevents creating objects externally
    SettingManager() {
        std::cout << "SettingManager Initialized (Only Once!)\n";
    }
};

int main() {
    std::cout << "--- Program Start ---\n";

    // Get the instance and modify data
    SettingManager & s1 = SettingManager::getInstance();
    s1.theme = "Dark Mode";
    s1.displayTheme();

    // Get the instance somewhere else in the program
    SettingManager& s2 = SettingManager::getInstance();
    s2.displayTheme(); // Will print "Dark Mode" because s1 and s2 are the exact same object

    std::cout << "--- Program End ---\n";
    return 0;
}