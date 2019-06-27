#include <iostream>
#include <vector>
using namespace std;
//typedef is just an alias
typedef int student_id;
typedef vector<pair<string, int>> pairlist_t;

student_id id{0};

student_id idGenerator(){
   return ++id;
}

bool hasDuplicates(pairlist_t pairlist){

}

int main(){
    cout << idGenerator() << endl;
    cout << typeid(pairlist_t).name() << endl;

    /**
     * Auto is to signify auto scope and duration.
     */ 
    auto id = idGenerator();

    cout << id;
}
