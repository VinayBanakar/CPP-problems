#include <iostream>
#include <functional>

using std::cout;
using std::cin;
using std::endl;

// Pass by references is esentially pass by address, compiler takes care of it.
void doSomething(int& x, int& y, int& z){
    x = 1;
    y = 1;
    z = 1;
}

/**
 * If the function parameter is assigned a different address, that will not impact the argument, 
 * since the function parameter is a copy, and changing the copy won’t impact the original. 
 * After changing the function parameter’s address, the function parameter and argument will point 
 * to different values, so dereferencing the parameter and changing the value will no longer affect 
 * the value pointed to by the argument.
 */
void doWhat(int* p){
    *p = 2;
    //p = nullptr;
}

// if we want to change the address an argument points to from within the function
void changePointer(int* &ptr){
    ptr = nullptr;
}

// Returning address only makes sense when you have dynamically allocated memory;
int* returnByAddress(int x){
    return &x; // return value by address
} //value destroyed here

//Return by reference is used to return the passed parameter itself.

int foo(int x){ return x*x;}

// C++ really passes everything by value! 
int main(){

    /////////////////////////////////////////////////////////////
    // Function pointers are useful primarily when you want to store 
    // functions in an array (or other structure), or when you need to pass 
    // a function to another function.
    /////////////////////////////////////////////////////////////

    int x,y,z;

    // If you want a function to return more than one value then you can do the following
    // Pass required as variables.
    doSomething(x,y,z);

    cout << x+y+z << endl;

    // You can also pass by address
    // Here its basically pass by value, where value is the address of the pointer.
    // A copy of the pointer address is given to the function. Hence changing the pointer
    // will have now affect to the pointer here, except you are changing the value the pointer
    // points to by derefrencing.
    int val = 5;
    doWhat(&val);
    cout << "val\t" << val << endl;

    int* ptr = &val;
    changePointer(ptr);

    if(ptr)
        cout << "*ptr\t" << *ptr << endl;
    else 
        cout << "ptr is null" << endl;

    //Retrun by address
    returnByAddress(val);

    // This fooPtr can be made to point any other function too.
    int (*fooPtr)(int) = foo;
    
    //In C++11 you can define func ptr like bellow
    std::function<int(int)> funcPtr = foo;

    cout << "fooPtr\t" << fooPtr(5) << endl;

    // With function pointers you can pass functions as arguments to other functions, 
    // these are called callback functions.
}