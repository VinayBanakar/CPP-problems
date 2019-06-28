#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;

void selectionSort(int* array, int len) {
    for(int startIndex = 0; startIndex < len -1; ++startIndex){

        int smallIndex = startIndex;
        for(int currentIndex = startIndex +1; currentIndex < len; ++ currentIndex){
            if(array[currentIndex] < array[smallIndex]){
                smallIndex = currentIndex;
            }
            std::swap(array[startIndex], array[smallIndex]);
        }
    }
}

void printArray(int* array, int len){
    for(int i=0; i< len; ++i){
        cout << array[i] << " ";
    }
    cout << std::endl;
}

int main(){
    int arraySize{0};
    cout << "Enter size of array: ";
    cin >> arraySize;
    // int array[arraySize]; // Shouldn't create an array with variable lenght, unless its declared as a constant.
    int* inputArray = new int[arraySize];
    for(int i = 0; i<arraySize;i++){
        cin >> inputArray[i];
    }
    cout << "Array before sort: " ;
    printArray(inputArray, arraySize);
    
    // O(N^2)
    selectionSort(inputArray, arraySize);
    
    // Bellow used introSort. O(N log N)
    //std::sort(inputArray,inputArray+arraySize);

    cout << "Array after sort: " ;
    printArray(inputArray, arraySize);

}