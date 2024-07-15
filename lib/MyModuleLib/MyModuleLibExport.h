#pragma once

#ifdef _WIN32
    #define MY_MODULE_LIB_API __declspec(dllexport)
#elif __GNUC__ >= 4
    #define MY_MODULE_LIB_API __attribute__((visibility("default")))
#else
    #define MY_MODULE_LIB_API
#endif
