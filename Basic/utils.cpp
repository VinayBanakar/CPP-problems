#include <iostream>
#include "utils.h"
using namespace values;
void doSomething() {
    // s_value will not be destroyed after doSomething call, by making it static you can retain its value.
    static int s_value = 1;
    ++ s_value;
    g_val = g_val + g_x;
    std::cout << "s_value\t" << s_value << std::endl;
}