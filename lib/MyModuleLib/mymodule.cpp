#include <iostream>

extern "C" void module_hello() {
    std::cout << "Hello from the module!" << std::endl;
}
