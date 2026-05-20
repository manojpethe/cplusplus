#include<iostream>
#include"manoj.h"

using namespace std;

class ClassC;

class ClassA{
private:
    int a = 100;
public:
ClassA(){
    cout << "constructor of class A ran."<< endl;
};
    void getA(){
        cout << "class A " << a << endl;
    };
    friend void showme(ClassC& obj);
};
class ClassB{
private:
    int b = 100;
public:
ClassB(){
    cout << "constructor of class B ran."<< endl;
};
    void getB(){
        cout << "class B " << b << endl;
    };
    friend void showme(ClassC& obj);
};

class ClassC: public ClassA, public ClassB {
    int c = 300;
    public:
    friend void showme( ClassC& obj );
};

void showme(ClassC& myClassCInstance ){
    cout << myClassCInstance.a  << " " << myClassCInstance.b  <<  " " << myClassCInstance.c << endl ;
};

namespace UtilFn {
    string info = "Manoj Pethe";
    int add(int a, int b){
        return a + b;
    }
}

int main(){

    ClassC myClassC;
    myClassC.getA();
    myClassC.getB();

    showme(myClassC);

    cout << UtilFn::add(2,2) << endl;

    cout << multiply(2,2)<< endl;
    cout << UtilFn::info<< endl;

    return 0;
}