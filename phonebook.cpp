#include<iostream>
#include<string>
#include "lib/common.h"
#include "lib/loginFunctions.h"
#include "lib/appPhonebook.h"
using namespace std;

int main(){
    
    string username;

    cout << "Welcome to Phonebook" << endl;
    ruler

    login(username);
    if (username == ""){
        return 0;
    }
    phonebookApp();
    return 0;
}