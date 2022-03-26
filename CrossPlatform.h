#ifndef _CrossPlatform
#define _CrossPlatform

    #ifdef _WIN32
        #define PAUSE system("pause");
    #endif //WIN32
    #ifdef linux
        #define PAUSE  
    #endif //linux

#endif //_CrossPlatform