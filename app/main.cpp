#include <iostream>
#include "add.h"      // static library
#include "mylib.h"    // shared library
#include "mymodule.h" // module library

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#elif defined(__linux__)
    #include <dlfcn.h>
#endif

typedef void (*f_hello)();

int main() {
    std::cout << "Build type: ";
    #ifndef NDEBUG
    std::cout << "Debug" << std::endl;
    #else
    std::cout << "Release" << std::endl;
    #endif
    std::cout << "Hello, World! (app)" << std::endl;
    static_hello();
    shared_hello();

#if defined(_WIN32) || defined(_WIN64)
    HMODULE handle = LoadLibrary(TEXT("MyModuleLib.dll"));
    if (!handle) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }
    f_hello m_hello = (f_hello) GetProcAddress(handle, "module_hello");
    if (!m_hello) {
        std::cerr << "Failed to get function address" << std::endl;
        FreeLibrary(handle);
        return 1;
    }
#elif defined(__linux__)
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
#endif

    m_hello();

#if defined(_WIN32) || defined(_WIN64)
    FreeLibrary(handle);
#elif defined(__linux__)
    dlclose(handle);
#endif

    return 0;
}
