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
}