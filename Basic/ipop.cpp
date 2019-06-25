#include<iostream>

using namespace std;

void print_factors(int i) {
    cout << "Factors of " << i << " : " << endl;
    for(int j = 1; j< i; ++j) {
        if(!(i % j))
            cout << j << " ";
    }
    cout << endl;
}

void print_factorial(int i) {
    long fact = 1;
    for(int j = i; j>0; --j) {
         fact = fact*j;
    }
    cout << "Factorial of " << i << " :" << fact << endl;
}

int main() {

    int i = 0;
    cout << "Enter a number ";
    cin >> i;
    print_factors(i);
    print_factorial(i);
}