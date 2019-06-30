#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[5] = {1,2,3,4,5};

    for(auto var : arr){
        var =1;
    }
    cout << "no&\t" << arr[2] << endl;
    for(auto& var : arr){
        var = 1;
    }
    cout << "yes&\t"<< arr[2] << endl;
}