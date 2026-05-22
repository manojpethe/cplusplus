#include<iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
};

int deduct(int a, int b){
    return a - b;
};


int main(){
    cout << sum(2,3) << endl;
    int (*functionPtr)(int a , int b) = sum ;
    cout << functionPtr(1,2) << endl;
    functionPtr = deduct ;
    cout << functionPtr(350,100) << endl;
}