#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct User{
    int age = 0;
    string name = "";
};


int main(){
    cout << "Hello!" << endl;
    vector<User> userList = {};
    User user1;
    user1.age = 10;
    user1.name = "Neel";
    User user2;
    user2.age = 50;
    user2.name = "Manoj";
    userList.push_back(user2);
    userList.push_back(user1);

    sort(userList.begin(),userList.end(),[](const User& a, const User& b) {
        return a.age < b.age;
    });

    for(int i = 0; i < userList.size(); i ++){
        cout << userList[i].name << " " << userList[i].age << endl;
    }

    return 0;
}