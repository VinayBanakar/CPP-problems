#include <iostream>
#include <string>
#include <utility> //for swap

using std::cout;
using std::cin;
using std::endl;

void printList(std::string *names, int len){
    cout << "[";
    for(int i = 0; i < len; ++i)
        cout << names[i] << " ";
    cout << "]\n";
}

//Selection sort - lexicographic
void sortList(std::string *names, int len){
    for(int startInd = 0; startInd < len-1 ; ++ startInd){
        int smallInd = startInd;
        for(int currInd = startInd+1; currInd < len; ++currInd){
            if(names[currInd] < names[smallInd])
                smallInd = currInd;
        }
        std::swap(names[startInd], names[smallInd]);
    }
}

int main() {
    cout << "Enter number of names you want to enter: ";
    int len{0};
    
    do {
        cin >> len;
        if(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "INVALID INPUT TRY AGAIN!\n";
        cout << "Enter: ";
        }
    } while(len == 0);

    std::string *nameList = new std::string[len]; // make sure you deleted this later.

    for(int i=0; i<len; ++i){
        cout << "name #" << i+1 << ": ";
        cin >> nameList[i];
    }

    cout << "Before sort:\n";
    printList(nameList, len);
    sortList(nameList, len);
    cout << "After sort:\n";
    printList(nameList, len);

    delete[] nameList;
    return 0;
}