#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> todoManager(string title){
    static vector<string> todoList = {"first", "second"};
    todoList.push_back(title);
    return todoList;
}

int main(){
    vector<string> mylist ;
    cout << "lets checkout function with static for state mgmt: " << endl;
    mylist =  todoManager("Hello World!");
    mylist =  todoManager("Hola World!");
    cout << mylist.size() << endl;
    for(short int i = 0; i < mylist.size(); i++){
        cout << mylist[i] << endl;
    }
}