#include<iostream>
#include<string.h>
using namespace std;

int main() {
    string rating;
    int ratingValue;
    cout << "Enter your rating: ";
    getline(cin, rating);
    cout << "Your rating is: " << rating << endl;
    try{
        ratingValue = stoi(rating);
    } catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a numeric value." << endl;
        return 1;
    }
    switch (ratingValue){
    case 1:
        puts("We will work on the problem and try to improve our service.");
        break;
    case 2:
        puts("We appreciate your feedback and will work to improve.");
        break;
    case 3:
        puts("Thank you for your rating!");
        break;
    case 4:
        puts("Thank you for your positive rating!");
        break;
    case 5:
        puts("We're glad you loved our service!");
        break;
    default:
        puts("Invalid rating. Please enter a value between 1 and 5.");
        return 1;
    }
    return 0;
}