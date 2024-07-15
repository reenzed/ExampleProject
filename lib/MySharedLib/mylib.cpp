#include <iostream>

#include "mylib.h"

MY_SHARED_LIB_API void shared_hello() {
    std::cout << "Hello, World! (MySharedLib)" << std::endl;
}
