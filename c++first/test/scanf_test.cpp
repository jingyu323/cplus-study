#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x=0;
    int j=0;

    printf("data[%d]=%d\n",0,x);
    scanf("d%",&x);
    while (x !=9999)  
    {
     
        printf("data[%d]=%d\n",j,x);
        scanf("%d",&x);
        j++;
    }
    return 0;
}
