#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct 
{
    char  data[MaxSize];
    int top;
} SqStatck ;

void InitStatck(SqStatck &S){

}


bool StackEmpty(SqStatck s){

}

bool Push(SqStatck &S, char x){

}

bool Pod(SqStatck s, char &x){

}

bool bracketCheck(char str[], int length){

    SqStatck S;
    InitStatck(S);

    for (int  i = 0; i < length; i++)
    {
        if(str[i] ==   "(" || str[i] == "{"  || str[i] == "[" ){
            Push(S,str[i])

        }
        

    }
    


}