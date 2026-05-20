#include<iostream>
#include<string>
using namespace std;


int main() {
short int lengthOfArray = 10;
short int myArray[lengthOfArray];

short int *myPointer = myArray;

    for( short int i = 0; i < lengthOfArray; i++) {
        *myPointer = i;
        myPointer++;
    }

for( short int i = 0; i < lengthOfArray; i++) {
    cout << myArray[i] << endl;
}
}
