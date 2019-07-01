#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class A{
    public:
        virtual const char* getValue(){ return "A";}
};

class B: public A{
    public:
        // fun signatures should match.
        virtual const char* getValue(){return "B";}
};

class C: public B{
    public:
        virtual const char* getValue(){return "C";}
};

int main(){
    B b;
    A& rand = b;

    /**
     * virtual keyword is for compiler to call the most derived function def/match for that object.
     * 
     * Note if a func is marked virtual all matching overides are also virtual, even if they are
     * not marked vitual.
     * 
     * Do not call virtual functions from derived constructors, because when derived class is created
     * the base portion is constructed first and derived portion does not exist it so it will be unable
     * to call the derived version of the function. Base version will be called instead.
     */

    cout << rand.getValue() << endl;
}