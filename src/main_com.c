#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char const *argv[])
{
    printf("1 - find E\n");
    printf("2 - transition from decimal\n");
    printf("3 - Exit programm\n");

    int option;
    if(scanf("%d",&option)){};

    while (option != 3)
    {
        switch (option)
        {
        case 1:
            int x;
            printf("-------------------\n");
            printf("Input int x\n");
            if(scanf("%d",&x)){};

            float e = E(x);

            printf("E is %f\n",e);
            printf("-------------------\n");
            
            if(scanf("%d",&option)){};
            break;

        case 2:
            long X;
            printf("-------------------\n");
            printf("Input decimal number\n");
            if(scanf("%ld",&X)){};
            char* bin = transition(X);

            printf("Your number is %s\n",bin);
            printf("-------------------\n");

            if(scanf("%d",&option)){};
            break;

        default:
            printf("invalid command\n");
            if(scanf("%d",&option)){};
            break;
        }
    }
    

    return 0;
}
