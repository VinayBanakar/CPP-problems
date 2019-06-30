#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

    const int ab = 2;
    const int* ptr = &ab;
    // *ptr = 6; // Thi is illegal.

    /**
     *  a pointer to a constant variable treats the variable as constant when 
     * it is accessed through the pointer, regardless of whether the variable 
     * was initially defined as const or not.
     */
    int bc = 5;
    const int* pt = &bc;
    cout << "*pt\t" << *pt << endl;
    bc = 6;
    //*pt = 6; // is again illegal
    cout << "*pt\t" << *pt << endl;
    pt = &ab; // This should work as pt is now pointing to another constant.
    cout << "*pt\t" << *pt << endl;

    /**
     * KEY POINTS:
     * A non-const pointer can be redirected to point to other addresses.
     * A const pointer always points to the same address, and this address can not be changed.
     * A pointer to a non-const value can change the value it is pointing to. These can not point 
     * to a const value.
     * A pointer to a const value treats the value as const (even if it is not), and thus can not 
     * change the value it is pointing to.
     */

    int i = 10;
    const int *p1{ &i }; // Non-const pointer to a const int
    int const *p2{ &i }; // Non-const pointer to a const int
    int *const p3{ &i }; // Const pointer to a non-const int
    const int *const p4{&i}; //const pointer to a const int.
//    *p1 = 1; // No
    p1 = nullptr; // Ok
    
//    *p2 = 1; // No
    p2 = nullptr; // Ok
    
    *p3 = 1; // Ok
//    p3 = nullptr; // No

//    *p4 = 1; //No 
//    p4 = nullptr; //No

}