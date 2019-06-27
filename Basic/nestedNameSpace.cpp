#include<iostream>

using std::cout;
using std::endl;

namespace foo::goo {
    int g_x = 5;
}

// Enums are distinct but not type safe.
enum class randColor{
    one_color, // assigned 0
    two_color // assiged 1
};

// Making it class makes it strongly typed and strongly scoped.
enum class randFruit{
    one_fruit, 
    two_fruit
};

namespace boo = foo::goo;
int main(){
    foo::goo::g_x = 6;
    cout << foo::goo::g_x << endl;
    cout << static_cast<float>(boo::g_x) << endl;
    cout << static_cast<float>(boo::g_x) / 10 << endl;

    randColor col = randColor::two_color;
    randFruit fru = randFruit::two_fruit;
    /**
     * If enums are not class then one enum can be compared to another and also cout can print it.
     */
    
 //   cout << "color\t" << randColor::two_color << endl;
 //   cout << "color\t" << col <<endl;

//    cout <<"what\t" << ((col == fru)? "same" : "not same") << endl;

    //Smae enums can be compared
    cout << "sameEnum\t" << ((col == randColor::one_color)? "unexpected":"expected") << endl;
}