#include<iostream>
#include<string>
#include<vector>

using namespace std;

namespace dev {
    string author = "Manoj Pethe";
    long int phone = 9823282613;
}

int main(){
    cout << "Hi Mom!" << endl;
    cout << dev::author << endl;
    cout << dev::phone << endl;

    int * intptr = new int(10);
    cout << "Value of Int Pointer: " << *intptr << endl;
    cout << "Value of Pointer: " << intptr << endl;
    cout << "Type of Pointer: " << typeid(intptr).name() << endl;
    
    delete(intptr);
    intptr = new int(20);
    cout << "Value of Int Pointer: " << *intptr << endl;
    cout << "Value of Pointer: " << intptr << endl;
    cout << "Type of Pointer: " << typeid(intptr).name() << endl;
    delete(intptr);

    int one = 1;
    int & anotherOne = one;

    cout << anotherOne << endl;

    int x = 10;
    int intArray[3];
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;

    for(int i = 0; i < size(intArray); i++ ){
        cout << " for loop " << intArray[i] << endl;
    }

    int iter = 0;
    while(iter < size(intArray)){
        cout << " while loop " << intArray[iter] << endl;
        iter++;
    }
    iter = 0;
    do{
        cout << " do while loop " << intArray[iter] << endl;
        iter++;  
    } while(iter < size(intArray));

    int command = 0;

    switch(command){
        case 0:
            cout << " switch case = 0" << endl;
            break;

        case 1:
            cout << " switch case = 1" << endl;
            break;

        case 3:
            cout << " switch case = 3" << endl;
            break;

        default:
            break; 
    }

    try{
        int x = 0;
        // throw std::string("error occured");
    } catch (const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 0;
    }

    vector<int> listOfNumbers;

    listOfNumbers.push_back(1);
    listOfNumbers.push_back(2);
    listOfNumbers.push_back(3);

    cout << "size of vector: " << listOfNumbers.size() << endl;
    cout << "first element of  vector: " << listOfNumbers[0] << endl;
    listOfNumbers.pop_back();
    cout << "size of vector: " << listOfNumbers.size() << endl;
    cout << "first element of  vector: " << listOfNumbers[1] << endl;
    listOfNumbers.push_back(4);
    listOfNumbers.insert(listOfNumbers.begin() + 0,1000);
    listOfNumbers.erase(listOfNumbers.begin() + 1);
    listOfNumbers.insert(listOfNumbers.begin() + 2,3000);
    cout << "size of vector: " << listOfNumbers.size() << endl;
    cout << "first element of  vector: " << listOfNumbers[0] << endl;
    for ( int i : listOfNumbers){
        cout << i << endl; 
    }

}