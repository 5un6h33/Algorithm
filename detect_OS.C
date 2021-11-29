#include <stdio.h>

int main() 
{
	#if __APPLE__
        #include "TargetConditionals.h"
        #if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
            printf("iPhone stimulator\n");
        #elif TARGET_OS_IPHONE
            printf("iPhone\n");
        #elif TARGET_OS_MAC
            printf("MacOS\n");
        #else
            printf("Other Apple OS\n");
        #endif
	#else
	    printf("Not an Apple OS\n");
	#endif
	return 0;
}