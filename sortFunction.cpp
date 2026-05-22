#include<iostream>
using namespace std;

int main(){
    cout << "SORT!" << endl;
    int myArray[5] = {16, 18, 48, 47 ,17};
    int newArray[5];
    int largestIntIndex = 0;
    int largestInt = 0;
    for(int i = 0; i < size(myArray) ; i++){
        // if(myArray[i] == -1){
        //     continue;
        // }
        for(int ni = 0 ; ni < size(myArray) ; ni++){
            if(myArray[ni] == -1){
                continue;
            }
            if(myArray[ni] > myArray[ni+1] ){
                cout << myArray[ni] << " > than " << myArray[ni+1] << endl;
                largestInt = myArray[ni];
                largestIntIndex = ni;
            }
            cout << "Iteration:" << ni << " " << myArray[ni] << " " <<  largestInt << " " << largestIntIndex  << endl;
        }
        // add the largest integer to newArray
        newArray[i] = largestInt;
        // update the value of existing array element to -1 to skip it next time.
        myArray[largestIntIndex] = -1;

    }
    for(int i = 0; i < 5; i++){
        cout << newArray[i] << endl;
    }

}