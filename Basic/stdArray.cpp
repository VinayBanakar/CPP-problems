#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

int main(){
    // Std arrays don't decay when passed to functions.
    std::array<int, 5> nArr;
    nArr = {3,23,5,10}; // Rest is set to 0.
    cout << nArr[4] << endl;
    cout << nArr.size() << endl; //size will work even if called inside a function as array won't decay.

    ////////  Always pass std::array by reference or const reference ////////

    cout << *nArr.begin() << endl;
    cout << *nArr.end() << endl;

    std::sort(nArr.begin(), nArr.end());

    for(auto& elem: nArr){
        cout << elem << " ";
    }
    cout << endl;
    // Iterating through the array in the right way.
    using index_t = std::array<int, 5>::size_type; // Because size() returns size_type.
    // std::size_t or you can also use this for i datatype.
    for(index_t i{0}; i< nArr.size(); ++i){
        cout << nArr[i] << " ";
    }

}