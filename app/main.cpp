#include <iostream>
#include "add.h"      // static library
#include "mylib.h"    // shared library
#include "mymodule.h" // module library

// Linux
#include <dlfcn.h>

typedef void (*f_hello)();

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Static Library: " << Add(2, 2) << std::endl;
    std::cout << "Shared Library: "; shared_hello();

    // Linux begin
    void* handle = dlopen("lib/MyModuleLib/libMyModuleLib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }
    dlerror(); // reset error
    f_hello m_hello = (f_hello) dlsym(handle, "module_hello");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'module_hello': " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }
    std::cout << "Module Library: "; m_hello();
    dlclose(handle);
    // Linux end
    
    #ifndef NDEBUG
    std::cout << "Debug" << std::endl;
    #endif
    return 0;
}
