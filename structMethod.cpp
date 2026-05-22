#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct MyStruct{
    int myNumber = 0;
    string myName  = "John Doe";

    MyStruct(int num, string name) : myNumber(num) , myName(name){};

    void display() {
        cout << myNumber << " " << myName << endl;
    };

    static void myMethod(){
        cout << "This is a simple static method, you cant access any variable in it from the struct" << endl;
    };
};


int main(){
    MyStruct mystruct(7,"Manoj");
    mystruct.display();
    mystruct.myMethod();
}