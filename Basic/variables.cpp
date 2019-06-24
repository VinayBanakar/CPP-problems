#include <iostream>
// Declare the namespace being used to avoid qualifying each method call
using namespace std;

int main() {
    auto i = 4;
    float b = 5.4;
    cout << "the value of i is " << i << endl;
    cout << "the value of i+b is " << i+b << endl;

    int k = 0;
    k = 1.4;  // truncated

    // Here even expressions have types, since all the terms have type int, it will be evaluated as int.
    float p = 9/5;
    float q = 9.0/5.0;
    cout << "the value of k is " << k << " and the value of p is " << p << " and q is " << q << endl;
}