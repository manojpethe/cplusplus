#include<iostream>
using namespace std;

int main(){
    cout << "SORT!" << endl;
    int myArray[5] = {16, 18, 48, 47 ,17};
    int newArray[5];
    int largestIntIndex = 0;
    int largestInt = 0;
    int nextInt = 0;
    for(int i = 0; i < size(myArray) ; i++){
        for(int ni = 0 ; ni < size(myArray) ; ni++){
            if(myArray[ni] == -1){ continue; }
            if(myArray[ni] < largestInt) { 
                cout << "largest int:" << largestInt << " is greater than " << myArray[ni] << endl;
                continue;
            }
            cout << "comparing: "<< myArray[ni] << " with " << myArray[ni+1] << endl;
            cout << "Debug: "<< ni+1 << " / " << size(myArray) << endl;
            if( ni+1 < size(myArray)){
                nextInt = myArray[ni+1];
            } else if ( ni+1 == size(myArray) ){
                nextInt = -1;
            }
            if(myArray[ni] > nextInt ){
                cout << myArray[ni] << " > than " << nextInt << endl;
                largestInt = myArray[ni];
                largestIntIndex = ni;
            }
            // cout << "inner loop:" << ni << endl;
            // cout << ":inner loop end:" << endl;
        }
        cout << "outer loop end:" << endl;

        // add the largest integer to newArray
        newArray[i] = largestInt;
        // update the value of existing array element to -1 to skip it next time.
        myArray[largestIntIndex] = -1;
        // resetting largest int to 0 so that next one can be picked up.
        largestInt = 0;
        // cout << "First element: "<< newArray[0] << endl;
        // for(int i = 0; i < 5; i++){
        //     cout << myArray[i] << endl;
        // }
    }
    for(int i = 0; i < 5; i++){
        cout << newArray[i] << endl;
    }

}