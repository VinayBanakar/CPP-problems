#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main(){
    // Std vectors much safer than doing your own memory allocations.
    // as they auto deallocate once out of scope.
    std::vector<int> arr{2,10,4,12}; // No need to give array lenght at compile time.

    cout << "arr\t" << arr.size() << endl;
    cout << arr[2] << endl;
    try {
        cout << arr.at(10) << endl;
    } catch(std::out_of_range e){
        std::cerr << "Out of bound exception caugth for "<< e.what() << endl;
    }

    //Vectors can be resized
    arr.resize(6); // The new elements will have 0s.
    cout << "arr\t" << arr.size() << endl;

    cout << "sizeof\t" << sizeof(arr) << endl;

    
    int len = 4;
    std::vector<int> vem{};
    vem.reserve(len);

    for (int j = 0; j < vem.size(); ++j){
        vem[j] = j; // You can use this as long memory is allocated for vector.

        // use this when vector is not initialized with size, or when it has just reserved memory.
        // If no size is set make sure you don;t use .size() for for loop.
        //vem.push_back(j); 
    }

    /**
     * vector internally use heap and allocate and deallocate automatically, however if 
     * you are allocating memory to heap like bellow then you are suppoed to deallocate 
     * it too.
     */
    // Example 1
    std::vector<int> *abc = new std::vector<int>{2,42,5,12};

    // Example 2
    std::vector<int> v{2,42,5,12};
    std::vector<int> *xyz = &v;
    
    /**
     * In the first example, vector v is dynamically allocated on the heap, so you have to clean it up.
     * In the second example, vector v is allocated on the stack, so it will clean itself up when it goes 
     * out of scope. So they are not the same.
     */

    cout << "*abc\t" << (*abc)[1] << endl;

}