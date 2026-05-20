#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class User {
    string username;
public:
    User(const string& name) : username(name) {}

    void notify(const string& videoTitle) {
        cout << username << " got notified: New video - " << videoTitle << endl;
    }
};

class SuperUser : public User {
    string username;
    string id;

public:
    SuperUser(const string& name) : username(name) {}

    void notify(const string& videoTitle) {
        cout << username << " got notified: New video - " << videoTitle << endl;
        cout << id << "I am super user!" << endl;
    }

    void setId( string id){
        this->id = id; 
    }
};

class Channel {
    vector<User*> subscribers;
public:
    void subscribe(User* sub) {
        subscribers.push_back(sub);
    }

    void unsubscribe(User* sub) {
        auto it = find(subscribers.begin(), subscribers.end(), sub);
        if (it != subscribers.end())
            subscribers.erase(it);
    }

    void uploadVideo(const string& title) {
        cout << "Channel uploaded: " << title << endl;
        for (auto* sub : subscribers)
            sub->notify(title);
    }
};



int main() {
    Channel cppNuts;

    User user1("Ram");
    User user2("Shyam");
    User user3("Mohan");
    SuperUser user4("Manoj");


    cppNuts.subscribe(&user1);
    cppNuts.subscribe(&user2);
    cppNuts.subscribe(&user3);

    cppNuts.uploadVideo("Observer Pattern in C++");

    cppNuts.unsubscribe(&user2);

    cppNuts.uploadVideo("Observer Pattern in Python");


}