#include <iostream>
using namespace std;

int getValue() {
    cout << "Enter a number: ";
    int input{0};
    cin >> input;

    return input;
}

void printDouble(int num, int val){
    cout << num << " doubled is: " << num*2 << endl;
    cout << val << " doubled is: " << val*2 << endl;
}

main() {
    /*
     * There is no guarantee that methods will be called from right to left.
     * Variables will always be called from right to left.
     */ 
    printDouble(getValue(), getValue());

    // So if you want order assign return values to a variables locally and call them.
    int ab1{getValue()};
    int ab2{getValue()};
    printDouble(ab1, ab2);
}