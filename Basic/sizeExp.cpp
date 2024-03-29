#include <iostream>
using namespace std;

int main() {
    long int li;
    long long int lli;
    cout << "long int \t" << sizeof(li) << endl;
    cout << "long long int \t" << sizeof(lli) << endl;

    double z{3.56e12};
    cout << "z\t" << z << endl;
    cout << "z size \t" << sizeof(z) << endl;

    bool ax{true};
    cout << "ax\t" << ax << endl;

    cout << boolalpha;
    ax = 5;
    cout << "ax\t" << ax << endl;
    ax = 0;
    cout << "ax\t" << ax << endl;

    //To use octal: start number with 0. 
    int x{012};
    cout << "x is in octal\t" << x << endl;
    // Number is printed as 10 because, cout by default prints decimal.

    //Hexa example
    int y{0xF};
    cout << "y hexadecimal in decimal is\t" << y << endl;

    int bin{};
    bin = 0xFF; 
    cout << "bin\t" << bin << endl;

    bin = 0b1111'1111;
    cout << "bin\t" << bin << endl;

    /*
     * Defining constant  macros is a bad idea, instread use constexpr vairables. 
     */
      constexpr int someConst {10};

      int t= (10, someConst);
      cout << "t\t" << t << endl;

      t= (11, someConst, ++x);
      cout << "t\t" << t << endl;
}