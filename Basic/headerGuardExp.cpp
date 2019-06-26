#include "square.h"
#include "geometry.h"
#include <iostream>

using namespace std;

int main(){
    // Making sure getSquareSides() is only declared once during preproccing. Have one copy of the code.
    cout << getSquareSides() << endl;
    int x{getSquareSides() + 1};
    // Use cerr for debugging as cout is buffered output.
    cerr << x;
}