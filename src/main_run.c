#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("0 - change realisation(default 1)\n");
    printf("1 - find E\n");
    printf("2 - transition from decimal\n");
    printf("3 - Exit programm\n");

    int implem = 1;
    void* library;
    library = dlopen("/home/artem/lab_os/lab_os_4/build/libimp1.so",RTLD_LAZY);
    if(!library) {
        fprintf(stderr,"dlopen() error: %s\n",dlerror());
        exit(1);
    }

    float (*E)(int);
    
    E =(float (*)(int)) dlsym(library, "E");
    if(!E){
        fprintf(stderr,"dlopen() error: %s\n",dlerror());
        exit(1);
    }

    char* (*transition)(long);

    transition = (char* (*)(long))dlsym(library, "transition");
    if(!transition){
        fprintf(stderr,"dlopen() error: %s\n",dlerror());
        exit(1);
    }


    int option; 
    if(scanf("%d",&option)){};

    while (option != 3)
    {
        switch (option)
        {
        case 0:

            dlclose(library);

            if(implem == 1) {
                library = dlopen("/home/artem/lab_os/lab_os_4/build/libimp2.so",RTLD_LAZY);
                if(!library) {
                    fprintf(stderr,"dlopen() error: %s\n",dlerror());
                    exit(1);
                }
                implem = 2;
            } else {
                library = dlopen("/home/artem/lab_os/lab_os_4/build/libimp1.so",RTLD_LAZY);
                if(!library) {
                    fprintf(stderr,"dlopen() error: %s\n",dlerror());
                    exit(1);
                }
                implem = 1;
            }

            E = (float (*)(int))dlsym(library, "E");
            if(!E){
                fprintf(stderr,"dlopen() error: %s\n",dlerror());
                exit(1);
            }

            transition = (char* (*)(long))dlsym(library, "transition");
            if(!transition){
                fprintf(stderr,"dlopen() error: %s\n",dlerror());
                exit(1);
            }

            printf("Switched implemetation to %d\n", implem);
            if(scanf("%d",&option)){};

            break;

        case 1:
            int x;
            printf("-------------------\n");
            printf("Input int x\n");
            if(!scanf("%d",&x)){};

            printf("E is %f\n",E(x)); 
            printf("-------------------\n");
            
            if(scanf("%d",&option)){};
            break;

        case 2:
            long X;
            printf("-------------------\n");
            printf("Input decimal number\n");
            if(scanf("%ld",&X)){};

            printf("Your number is %s\n",transition(X));

            printf("-------------------\n");

            if(scanf("%d",&option)){};
            break;

        default:
            printf("invalid command\n");
            if(scanf("%d",&option)){};
            break;
        }
       
    }
     dlclose(library);





    return 0;
}
