#include <stdio.h>
#include <stdlib.h>


int Fib(int n){
   if(n==0){
    return 0 ;

   } else if(n == 1){
     return 1;
   }else{
    return  Fib(n-1) + Fib(n-2);
   }

}


int main(int argc, char const *argv[])
{
    /* code */

    int x= Fib(10);
printf("x = %d",x);

    return 0;
}
