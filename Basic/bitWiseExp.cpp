#include <iostream>
#include <bitset>
using namespace std;
struct Bits
{
    unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
    friend std::ostream& operator <<(std::ostream& os, Bits const& a){
        return os << a.b0 << a.b1 << a.b2 << a.b3 << a.b4 << a.b5 << a.b6 << a.b7;
    }
};

int main() {
    Bits bits;

    cout << bits << endl;
    bits.b2 = 1;
    bits.b5 = 1;
    cout << bits << endl;

    unsigned char someCond = 1 << 0;
    unsigned char someOtherCond = 1 << 1;

    bitset<8> newBits(0x2);
    cout << "newBits \t" << newBits << endl;
    newBits.set(0x5); // Sets the sixth element from left to 1 | bits.reset will set it back to 0.
    cout << "newBits \t" << newBits << endl;
    newBits.flip(0x1); // Flips seond element from left.
    cout << "newBits \t" << newBits << endl;
    newBits.flip(0x3);

    //BITMASK
     const unsigned int lowMask = 0xF; // (hex for 0000 0000 0000 1111)
     newBits &= lowMask;
     cout << "newBits with mask\t" << newBits << endl;

    int hexV;
    cout << "Enter a hex value: ";
    cin >> hex >> hexV;
    cout << hexV;
}