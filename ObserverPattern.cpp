#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Subscriber
{
private:
    string name = "";
public:
    Subscriber(string name): name(name){};

    void notify(string message){
        cout << name << ":"<< message << endl;
    }
};

class Observable{
    private:
    vector<Subscriber*> subscribers = {};

    public:
    void subscribe(Subscriber* user){
        subscribers.push_back(user);
    };

    void notifyAll(string message){
        for(Subscriber * user : subscribers){
            user->notify(message);
        }
    };

};

int main(){

    cout << "Hello!" << endl;
    Observable channel;
    Subscriber user1("Manoj");
    Subscriber user2("Ashish");

    channel.subscribe(&user1);
    channel.subscribe(&user2);

    channel.notifyAll("new Audio release of Hozier");


}
