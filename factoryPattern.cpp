#include<iostream>
#include <memory>
#include <string>
using namespace std;

class Car {
private:
    string name = "";
    string transimission = "";
public:
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void changeGear() = 0;
    virtual void pressGas() = 0;
    virtual void pressBrake() = 0;
    virtual void pressClutch() = 0;
};

class Tesla : public Car {
private:
    string name = "";
    string transimission = "";
public:
    Tesla(string name, string transmission){
        this->name = name;
        this->transimission = transimission;
    };
    void startEngine(){
        cout << this->name << ": Engine Started"<< endl;
    };
    void stopEngine(){
        cout << this->name << ": Engine Stopped"<< endl;
    };
    void changeGear(){
        cout << this->name << ": Hey I have autotranmsission"<< endl;
    };
    void pressGas(){
        cout << this->name << ": Vroom Vroom"<< endl;
    };
    void pressBrake(){
        cout << this->name << ": Oh Crap...........!"<< endl;
    };
    void pressClutch(){
        cout << this->name << ": Slowing down.... phew..."<< endl;
    };

    ~Tesla(){}

};


class Suzuki : public Car {
private:
    string name = "";
    string transimission = "";
public:
    Suzuki(string name, string transmission){
        this->name = name;
        this->transimission = transimission;
    };
    void startEngine(){
        cout << this->name << ": Engine Started"<< endl;
    };
    void stopEngine(){
        cout << this->name << ": Engine Stopped"<< endl;
    };
    void changeGear(){
        cout << this->name << ": Gear changed!!"<< endl;
    };
    void pressGas(){
        cout << this->name << ": Vroom Vroom"<< endl;
    };
    void pressBrake(){
        cout << this->name << ": Oh Crap...........!"<< endl;
    };
    void pressClutch(){
        cout << this->name << ": Slowing down.... phew..."<< endl;
    };

    ~Suzuki(){}

};


class CarFactory {
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

    cout << "--- Factory Pattern Execution ---" << endl;

    The client doesn't use the 'Tesla' class directly. 
    It asks the Factory to build a car.
    unique_ptr<Car> myCar = CarFactory::buildCar("Tesla", "Model 3");

    if (myCar) {
        myCar->startEngine();
        myCar->changeGear();
        myCar->pressGas();
        myCar->pressBrake();
    } else {
        cout << "Car type not recognized by factory." << endl;
    }

    cout << "Factory Pattern"<< endl;
    return 0;

}