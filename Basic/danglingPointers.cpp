#include <iostream>
using namespace std;

void doSomething(){
    int *po = new int(6);

    cout << "*po\t" << typeid(*po).name() << "\t" << *po << endl;
}

int main(){
    int* ab = new int(5);
    cout << "&ab\t" << typeid(&ab).name() << "\t" << &ab << endl;

    delete ab;
    cout << "ab\t" << typeid(ab).name() << "\t" << ab << endl;

    cout << "*ab\t" << typeid(*ab).name() << "\t" << *ab << endl;

    /**
     * ====================== IMPORTANT ======================
     * 
     * Dynamically allocated memory stays allocated until it is 
     * explicitly deallocated or until the program ends, dynamically 
     * allocated memory has no predetermined duration
     * 
     * Here value of 'ab' will give the address of the int object that stores 5 in the 
     * heap. and &ab will give the address of the pointer ab itself. and *ab will give 
     * the value of the object ab is pointing to, in this case 5.
     * 
     * After delete ab; the ab variable exists but the memory its pointing to is let go of.
     * delete ab; will delte the object and stops pointing to memory in the heap. Dereference 
     * Now this acquired heap memory is given back to the OS, but the allocator will keep
     * it until process ends to reuse it when memory is needed again. As requesting memory
     * from OS is a heavy operation.
     * 
     * After delete ab; trying *ab will give undefined behavior (UB). and * ab is adangling pointer.
     * Trying to derefrence meomry once again will also cause UB.
     * 
     * After deleting the pointer, make sure you set the pointer to null or 0 to avoid UB.
     */

    ab=0;
    ab = nullptr; //or
    //cout << "*ab\t" << typeid(*ab).name() << "\t" << *ab << endl; //Segfault.

    /**
     * ALSO MAKE SURE:
     * When you are doing 'new' and requesting for memory you do exception handling or check for null.
     * requesting memory can rarely fail, but when it does be prepared.
     */

    int* value = new (std::nothrow)int;
    if(!value){
        cout << "DID NOT ALLOCATE MEMORY!";
        exit(0);
    }

    // Memory leak problems

    /**
     * pointer 'po' is destroyed at the end of doSomething due to end of scope. Now there is now way
     * to derefernce the acquired memory as the program has lost the reference to it.
     */
    doSomething();

    /**
     * Here pointer 'op' when set with val address, it will lose the memory address it had previously,
     * Now there is no way to free value 6 from the heap.
     */
    int val = 5;
    int *op = new int(6);
    // delete op; // this will free up allocated memory from previous line.
    op = &val;
    op = new int; // By doing double allocation old address is lost again.
}