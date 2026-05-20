#include<iostream>
using namespace std;

void login(string &username){
    string password;

    cout << "Please enter username:";
    getline(std::cin, username);

    cout << "Please enter password:";
    getline(std::cin, password);

    if(username == "manoj" && password == "manoj" ){
        cout << "You have successfully logged in.." << endl;
    } else {
        username = "";
        cout << "Authentication Failure.." << endl;
    }
}