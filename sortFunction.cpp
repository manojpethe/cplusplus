#include<iostream>
using namespace std;

int main(){
    cout << "SORT!" << endl;
    int myArray[5] = {16, 18, 48, 47 ,17};
    int newArray[5];
    int largestIntIndex = 0;
    int largestInt = 0;
    for(int ni = 1 ; ni < size(myArray) ; ni++){
        if(myArray[ni] == -1){
            continue;
        }
        if(myArray[ni-1] > myArray[ni] && myArray[ni-1] > largestInt ){
            cout << myArray[ni-1] << " > than " << myArray[ni] << endl;
            largestInt = myArray[ni-1];
            largestIntIndex = ni-1;
        }
        cout << myArray[ni] << " " <<  largestInt << " " << largestIntIndex  << endl;
    }

}