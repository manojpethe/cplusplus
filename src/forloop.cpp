#include<iostream>
#include<string>
using namespace std;

class Person {
private:
    char gender;
    short int age;
    string name;

public:
    Person(short int age, string name, char gender) {
        this->age = age;
        this->name = name;
        this->gender = gender;
    };
    
    void setGender(char gender) {
        this->gender = gender;
    };

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    };
};

int main() {

    Person people[] = {
        Person(25, "Alice", 'F'),
        Person(30, "Bob", 'M'),
        Person(35, "Charlie", 'M'),
        Person(40, "David", 'M'),
        Person(45, "Eve", 'F')
    };

    // for (Person& person : people) {
    //     person.setGender('X'); // This will cause a compilation error because setGender is private
    //     person.displayInfo();
    // }

    // long age = 100;
    // printf("The age of the oldest person is:%ld \n",sizeof(age)*4);

    short int age = 100;

    puts(typeid("").name());

    return 0;
}