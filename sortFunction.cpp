#include<iostream>
using namespace std;

int main(){
    cout << "SORT!" << endl;
    int myArray[5] = {16, 18, 48, 47 ,17};
    int newArray[5];
    int largestIntIndex = 0;
    int largestInt = 0;
    for(int ni = 0 ; ni < size(myArray) ; ni++){
        if(myArray[ni] == -1){
            continue;
        }
        if(myArray[ni] > myArray[ni+1] && myArray[ni] > largestInt ){
            cout << myArray[ni] << " > than " << myArray[ni+1] << endl;
            largestInt = myArray[ni];
            largestIntIndex = ni;
        }
        cout << "Iteration:" << ni << " " << myArray[ni] << " " <<  largestInt << " " << largestIntIndex  << endl;
    }

}