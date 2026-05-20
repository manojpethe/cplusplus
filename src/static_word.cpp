#include<iostream>
using namespace std;

int getCounter(int increment = 0) {
    static int count = 1; // This variable retains its value between function calls
    count += increment;
    return count;
}

int main() {
    cout << "Counter: " << getCounter() << endl; // Output: Counter: 1
    cout << "Counter: " << getCounter(5) << endl; // Output: Counter: 6
    cout << "Counter: " << getCounter(-2) << endl; // Output: Counter: 4
    return 0;
}