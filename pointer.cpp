#include<iostream>
using namespace std;
#define LOG(x) count<< x << endl;

class User{
    private:
    string name = "";
    public:
    string getName() const{
        return name;
    };
    void setName(const string& name){
        this->name = name;
    };
};

int main(){
    int myNumber = 20;
    int * localptr;
    localptr = &myNumber;
    int * heapptr = new int(0);
    float * floatptr = new float(100.101);
    string * stringptr = new string("Hello");
    cout << "value of *ptr: " << *heapptr << endl;
    *heapptr  = 100;
    cout << "value of *ptr: " << *heapptr << endl;
    cout << "value of *localptr: " << *localptr << endl;
    
    cout << "value of *floatptr: " << *floatptr << endl;
    cout << "value of *stringptr: " << *stringptr << endl;
    delete heapptr;
    delete floatptr;
    delete stringptr;

    // 1. Create the object on the heap using 'new'
    User* userPtr = new User();

    // 2. Use the arrow operator (->) to modify and access it
    userPtr->setName("Bob");
    std::cout << "User's Name: " << userPtr->getName() << std::endl;

    // 3. Manually free the memory!
    delete userPtr; 
    
    // 4. Good practice: set to nullptr so you don't accidentally use it again
    userPtr = nullptr;

}