#include<iostream>
#include<string>
using namespace std;

class Animal{
    protected:
    string name = "";
    string sound = "";

    public:
    Animal(string name, string sound): name(name), sound(sound){};
    
    virtual void showInfo() = 0;
};

class Dog: public Animal{

    public:
    Dog(string name, string sound): name(name), sound(sound){};

     // Getter
    string getName() { return name; };
    string getSound() { return sound; };

    void showInfo(){
        cout << "I am "<< getName() << ", I make sound "<< getSound() << endl;
    };

};

class AnimalFactory {
public:
    // This static method decides what car to build based on user input
    static unique_ptr<Car> buildCar(const string& type, const string& model) {
        if (type == "Tesla") {
            return make_unique<Tesla>(model, "Automatic");
        } else if ( type == "Suzuki") {
            return make_unique<Suzuki>(model, "Manual");
        }
        // You can add other cars here easily later (e.g., BMW, Ford)
        return nullptr;
    }
};

int main(){

    cout << "Factory pattern:" << endl;
    Dog dog("Dog", "Woof Woof");
    dog.showInfo();

}