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

    cout << "size(arr)\t" << sizeof(arr) << endl;
    cout << "size(*arr)\t" << sizeof(*arr) << endl;
    cout << "size(&arr)\t" << sizeof(&arr) << endl;

    printValues(arr, sizeof(arr)/sizeof(arr[0])); //array automatically dcecays to pointer.

    char* setnence = "Is this a sentence?\n";
    cout << setnence;
    cout << setnence << endl;
}