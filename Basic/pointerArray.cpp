#include <iostream>

using namespace std;

void printValues(int* arr, int len) {
    for(int i =0;i<len;++i){
        cout << arr[i] << " ";
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout << "arr[0]\t" << &arr[0] << endl;
    cout << "arr[1]\t" << &arr[1] << endl;
    cout << "&arr\t" << &arr << endl;
    cout << "*arr\t" << *arr << endl;
    cout << "arr\t" << arr << endl;

    cout << "size(arr)\t" << sizeof(arr) << endl;
    cout << "size(*arr)\t" << sizeof(*arr) << endl;
    cout << "size(&arr)\t" << sizeof(&arr) << endl;

    printValues(arr, sizeof(arr)/sizeof(arr[0])); //array automatically dcecays to pointer.

    const char* setnence = "Is this a sentence?\n";
    cout << setnence;
    cout << *setnence << endl;

    //Dynamic arrays

    cout << "enter array lenght:";
    int len;
    cin >> len;
    int* dynArr = new int[len];

    cout << *dynArr << endl;
    delete[] dynArr;

    int* dynZarr = new int[6]{1,2,3,4,5,6}; // Size must be expliccitly told for dynamic errors.
    delete[] dynZarr;

}