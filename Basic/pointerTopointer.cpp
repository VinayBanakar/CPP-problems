#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int value = 5;
    int* ptr = &value;
    int** ptrptr = &ptr;

    cout << "ptr\t" << ptr << endl;
    cout << "*ptr\t" << *ptr << endl;
    cout << "*ptrptr\t" << *ptrptr << endl;
    cout << "**ptrptr\t" << **ptrptr << endl;

    ptrptr = nullptr;

    // Array pointers
    auto array = new int[5][4];
    cout << "array\t" << typeid(array).name() << endl; // PA4_i - [P]ointer to [A]rray of size [4] holding type [i]nt
    for(int i = 0;i<5;++i) {
        for(int j = 0; j<4; ++j){
            array[i][j] = i+j;
        }
    }
    cout << "array\t" << array[1][1] << endl;
    int **arr = new int*[5];
    cout << "arr\t" << typeid(arr).name() << endl;
    for(int count = 0; count < 5; count++){
        arr[count] = new int[4];
    }

    for(int i = 0;i<5;++i) {
        for(int j = i; j<4; ++j){
            arr[i][j] = i+j;
        }
    }
    cout << "arr\t" << arr[1][1] << endl;
}