#include<iostream>
using namespace std;
#include "utils.h"

int main(){
    cout << "g_val\t" << values::g_val << endl;
    cout << "g_x\t" << values::g_x << endl;

    doSomething();

    cout << "g_val\t" << values::g_val << endl;
    cout << "g_x\t" << values::g_x << endl;

    doSomething();
}