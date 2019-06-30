#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

struct Student
{
    int studentId;
    std::string studentName;
};

void populateInfo(Student[], int, int&);
void printStudentInfo(Student (&)[5], int);

// ref is a reference to the argument passed in, not a copy
void doSomething(int& ref, int (&arr)[5]){
    ref = 6;
    int length{ sizeof(arr) / sizeof(arr[0]) }; // we can now do this since the array won't decay
    arr[1] = length;
}

int main(){
    int val = 5;
    int &ref = val; // Here & does not mean address of ref but it means "reference to".
    cout << "=============" << endl;
    cout << "ref\t" << ref << endl;
    cout << "val\t" << val << endl;
    ref = 6;
    cout << "=============" << endl;
    cout << "ref\t" << ref << endl;
    cout << "val\t" << val << endl;
    cout << "=============" << endl;
    cout << "&ref\t" << &ref << endl;
    cout << "&val\t" << &val << endl;

    /**
     * Unlike pointers refernces should be initialized. Pointers can null value.
     * There is no such thing as as null refernces.
     */
    //int &refValue; 
    // int &refValue = 5; //Is also illegal as reference should reference a variable.

    int a = 2;
    int b = 3;
    int& y = a;
    cout << "=============" << endl;
    cout << "a\t" << a << endl;
    cout << "b\t" << b << endl;
    cout << "y\t" << y << endl;
    y = b; // Setting y to b will also changes a since y is a reference of a.
    cout << "=============" << endl;
    cout << "a\t" << a << endl;
    cout << "b\t" << b << endl;
    cout << "y\t" << y << endl;

    /**
     * As you can see bellow, a pointer pointing an object can be changed to point
     * another object, a refernce on the other hand can't be. Moreover refernces need
     * not "dereference" to get the value.
     * 
     * "references are typically implemented by the compiler as pointers"
     * 
     * Refrences can also act as aliases for long member selections. Ex:
     * something.other.valu1 = 5;
     * &ref = something.other.valu1;
     * now you can just ref = 10; to change the value.
     * 
     * Another way is to use macros: #define ref something.other.valu1, but use references
     * as compiler can optimize it and these definitions have scope limitations.
     * 
     * You can make memeber selection on references too.
     * Example: now from above ref.value1.value2 can also be done.
     * However with a pointer you will have to dereference the pointer to do member selctions. Ex:
     * Struct s_X { int abc; int xyz;};
     * s_X x;
     * int* ptr = x;
     * int& ref = x;
     * 
     * // To set abc to 5
     * ref.abc = 5;
     * (*ptr).abc = 5;
     * 
     * // Because dereferencing pointer is weird: C++ have '->'
     * ptr->abc = 5;
     * // '->' can be used to access struct/class variables without specifically dereferencing the pointer.
     * 
     */
    b = 10;
    cout << "===== Pointer =====\n";
    int* p = &a;
    cout << "=============" << endl;
    cout << "a\t" << a << endl;
    cout << "b\t" << b << endl;
    cout << "p\t" << *p << endl;
    p = &b;
    cout << "=============" << endl;
    cout << "a\t" << a << endl;
    cout << "b\t" << b << endl;
    cout << "p\t" << *p << endl;

    //int* arr = new int[5]();
    int arr[]{1,2,3,4,5};
    // References as function params
    doSomething(b,arr); // note that this argument does not need to be a reference
    cout << "======doSomething=======" << endl;
    cout << "b\t" << b << endl;
    cout << "cout[1]\t" << *(arr+1) << endl;

    /**
     * WHEN TO USE COPY ARGUMENTS AND WHEN TO USE REFERENCES
     * 
     * Types whose size is 1, 2, 4, or 8 bytes: Copy 
     * Everything else: Reference
     * If you're not sure about the size of a user-defined type: Reference.
     */

    //Const + references
    int x = 10;
    const int& r_x = x;
    x = 11;
    // r_x = 12; // This is not okay

    const int h = 11;
    // int& r_h = h; // This is not okay. Compilation error.


    Student StudentList[5];
    int len = sizeof(StudentList)/sizeof(StudentList[0]);
    int currId = 1;
    populateInfo(StudentList, len, currId);
    printStudentInfo(StudentList, len);

    //Creating with new
    Student* stoo = new Student[6]; // delete this later.
    len = sizeof(stoo)/sizeof(stoo[0]);
    cout << "len====="<<len<< endl;
    populateInfo(stoo, len, currId);
}

void populateInfo(Student StudentList[], int len, int& currId){
    for(int i = 0; i< len; ++i){
        (StudentList+i)->studentId = currId;
        (StudentList+i)->studentName = "ABC";
        currId++;
    }
}
void printStudentInfo(Student (&StudentList)[5], int len){
    for(int i = 0; i< len; ++i){
        cout << StudentList[i].studentId << endl;
        cout << StudentList[i].studentName<< endl;
    }
}