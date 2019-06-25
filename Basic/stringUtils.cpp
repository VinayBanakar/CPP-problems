#include <string>
using namespace std;

int compare(string x, string y) {
    if(x.length() < y.length()) 
        return -1;
    else if (x.length() == y.length())
        return 0;
    else 
        return 1;
}

int lexicographic_compare(string x, string y) {
    if(x<y)
        return -1;
    else if( x == y )
        return 0;
    else
        return 1;
}