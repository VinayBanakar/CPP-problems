#include <iostream>
#include <string>
// Header files simply give an option to do forwad declaration in a different file.
#include "stringUtils.h"


using namespace std;

void do_nothing(const int &x) { }

int main() {
    string s1, s2;
    // Uninitialized number need not be 0, and can be anything.
    // Gets assigned a value already present in the memory.
    // CPP does not initialize variables to 0. 
    int x;
    cout << "Uninitialized x: " << x << endl;

    do_nothing(x);

    cout << "After do nothing x is: " << x << endl;

    cout << "Enter first string s1:\t";
    //cin >> s1;
    getline(cin,s1);
    cout << "Enter second string s2:\t";
    cin >> s2;

    cout << "Result:\t" << compare(s1,s2) << endl << "Result lexico:\t" << lexicographic_compare(s1,s2) << endl;
}