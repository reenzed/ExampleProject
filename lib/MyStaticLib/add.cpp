#include <iostream>

#include "add.h"

int Add(int x, int y) {
    return x + y;
}

void static_hello()
{
    std::cout << "Hello, World! (MyStaticLib)" << std::endl;
}
