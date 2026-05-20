#include<iostream>
using namespace std;


class User {
    private:
        string name = "";
        int age = 0;
        char gender = 'U';
        string email = "";
        string phoneNumber = "";

    protected:
        string birthdate = "1990.01.01";
        string password = "defaultPassword";
        string occupation = "Unknown";

        void displayProtectedInfo() {
            cout << "Birthdate: " << birthdate << ", Occupation: " << occupation << endl;
        }

    public:
        User(string name, int age, char gender) : name(name), age(age), gender(gender) {}
        void displayInfo() {
            cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
            displayProtectedInfo();
        }
        friend void setPassword(User& user, string newPassword);
        friend int authenticate(User& user, string password);
        friend int apiAuthenticate(User& user, string password);
};

void setPassword(User& user, string newPassword) {
    cout << "Setting password for user: " << user.name << endl;
    user.password = newPassword;
}

int authenticate(User& user, string password) {
    if (user.password == password) {
        // cout << "Authentication successful for user: " << user.name << endl;
        return 1;
    } else {
        // cout << "Authentication failed for user: " << user.name << endl;
        return 0;
    }
}

int apiAuthenticate(User& user, string password) {
    cout << "API Authentication attempt for user: " << user.name << endl;
    return authenticate(user, password);
}



int main() {
    cout << "Hello, World!" << endl; // Output: Hello, World!

    User user("Alice", 30, 'F');
    user.displayInfo(); // Output: Name

    cout << "Authentication result for Alice: " << authenticate(user, "defaultPassword1") << endl; // Output: Authentication successful for user: Alice

    setPassword(user, "newSecurePassword123");

    cout << "Authentication result for Alice: " << authenticate(user, "newSecurePassword123") << endl; // Output: Authentication successful for user: Alice

    cout << "API Authentication result for Alice: " << apiAuthenticate(user, "newSecurePassword123") << endl; // Output: API Authentication attempt for user: Alice

    return 0;
}