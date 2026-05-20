#include<iostream>
using namespace std;

int add(int a = 0, int b = 0);
int subtract(int a = 0, int b = 0);
void doSomething(int (*fnPtr)(int,int), int a = 0, int b = 0);

int main(){

    int (*funPtr)(int a, int b);
    funPtr = &add;
    doSomething(funPtr,100,1);
    funPtr = &subtract;
    doSomething(funPtr, 100, 200);
    return 0;
}

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

void doSomething(int (*fnPtr)(int,int), int a, int b){
    cout << "Two numbers are:"<< a << " & " << b << endl;
    cout << "Calculated value is:" << fnPtr(a,b) << endl;
};