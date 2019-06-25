#include <iostream>
using namespace std;

#define NEW_CONST "abc" 

void foo() {
#define NEW_SOME "bro"
}

void something(); // forward declaration
main() {
#ifdef NEW_CONST
    cout << "Example:\t" << NEW_CONST << endl;
#endif

#ifndef NEW_VAR
    cout << "No var macro present" << endl;
#endif

#if 0
     // Don't compile any of this 
     // until this block ends.
     // Doesn't mean syntax errors won't be checked
    cout << "HERE I AMMMM";
#endif

    // NEW_SOME will print even if the method is not called.
    cout << "will this print? " << NEW_SOME << endl;

    something();
#ifdef VAL_SOME
    cout << "WHAAAT";
#endif
}

void something(){
#define VAL_SOME "this will not work"
}