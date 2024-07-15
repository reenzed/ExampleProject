#pragma once

#ifdef MY_SHARED_LIB_BUILD
    #ifdef _WIN32
        #define MY_SHARED_LIB_API __declspec(dllexport)
    #elif __GNUC__ >= 4
        #define MY_SHARED_LIB_API __attribute__((visibility("default")))
    #else
        #define MY_SHARED_LIB_API
    #endif
#else
    #ifdef _WIN32
        #define MY_SHARED_LIB_API __declspec(dllimport)
    #else
        #define MY_SHARED_LIB_API
    #endif
#endif
