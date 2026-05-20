#include<iostream>
#include<vector>
using namespace std;


struct User {
    string name;
    int age;
};

int main() {
    vector<User> users; // Create an empty vector of User objects

    // Add some users to the vector
    users.push_back(User{"Alice", 25});
    users.push_back(User{"Bob", 30});
    users.push_back(User{"Charlie", 35});

    // Display the contents of the vector
    cout << "Users in the vector: " << endl;
    for (size_t i = 0; i < users.size(); i++) {
        cout << "Name: " << users[i].name << ", Age: " << users[i].age << endl;
    }


    return 0;
}