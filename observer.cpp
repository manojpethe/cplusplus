#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Subscriber {
public:
    virtual void notify(const string& videoTitle) = 0;
};

class Channel {
    vector<Subscriber*> subscribers;
public:
    void subscribe(Subscriber* sub) {
        subscribers.push_back(sub);
    }

    void unsubscribe(Subscriber* sub) {
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

class User : public Subscriber {
    string username;
public:
    User(const string& name) : username(name) {}

    void notify(const string& videoTitle) override {
        cout << username << " got notified: New video - " << videoTitle << endl;
    }
};

class SuperUser : public Subscriber {
    string username;
    short int id = 999;
public:
    SuperUser(const string& name) : username(name) {}

    void setId(short int id){
        this->id = id;
    }

    short int getId( short int id){
        return id;
    }

    void notify(const string& videoTitle) override {
        // cout << username << " got notified: New video - " << videoTitle << endl;
        cout << username << " " << id << " "<< " Super user got notified: New video - " << videoTitle << endl;
        cout << "----I am super user -------------" << endl;
    }
};

int main() {
    Channel cppNuts;

    User user1("Ram");
    User user2("Shyam");
    User user3("Mohan");

    SuperUser user4("Manoj");

    user4.setId(100);

    cppNuts.subscribe(&user1);
    cppNuts.subscribe(&user2);
    cppNuts.subscribe(&user3);

    cppNuts.subscribe(&user4);

    cppNuts.uploadVideo("Observer Pattern in C++");

    cppNuts.unsubscribe(&user2);

    cppNuts.uploadVideo("Observer Pattern in Python");


}