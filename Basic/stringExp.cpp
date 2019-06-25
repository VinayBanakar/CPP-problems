#include <iostream>
#include <string>
#include "stringUtils.h"

using namespace std;

int main() {
    string s1, s2;

    cout << "Enter first string s1:\t";
    cin >> s1;
    cout << "Enter second string s2:\t";
    cin >> s2;

    cout << "Result:\t" << compare(s1,s2) << endl << "Result lexico:\t" << lexicographic_compare(s1,s2) << endl;
}