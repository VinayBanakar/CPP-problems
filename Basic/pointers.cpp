#include <iostream>

#include <iostream>

struct randomVal {
    int ax, bx, cx;
};

void foo(int *&p)
{
    // p is a reference to a pointer.  We'll cover references (and references to pointers) later in this chapter.
    // We're using this to trick the compiler into thinking p could be modified, so it won't complain about p being uninitialized.
    // This isn't something you'll ever want to do intentionally.
    *p = 100;
    std::cout << "foo *g" << *p << std::endl;
}

int main(){
    int x = 50;
    std::cout << "x\t" << x << std::endl;
    std::cout << "address x\t" << &x << std::endl;
    std::cout << "value from address\t" << *(&x) << std::endl;

    int* abc, xyz; //here abc is an int pointer, where as xyz is just int.
    // An integer pointer translates to a pointer to an integer.

    int *y = &x;
    int *z;
    z = &x;
    double p = 24;
    double* ty = &p;
    std::cout << y <<std::endl;
    std::cout << *y <<std::endl;
    std::cout << &y << std::endl;
    std::cout << "z\t "<<z << std::endl;
    std::cout << "*(&x)\t" << *(&x) << std::endl;
    std::cout << "y * ty " << *y * *ty << std::endl;

    //In c++ you cannot assgin memroy address to pointer directly
    // So type cast it.
    // double *dPtr = (double *)0x7ffeeba39a3c;
    // *dPtr = 5.2;
    // std::cout << dPtr;

    int* g;
    foo(g);
    std::cout << "*g" << *g << std::endl;

    randomVal* randomVal1;
    std::cout << "sizeOf: randomVal " << sizeof(randomVal1) << std::endl;
    std::cout << "z " << z << "z " << sizeof(z) << std::endl;
}