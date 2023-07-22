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

bool Pop(SqStatck s, char &x){

}

bool bracketCheck(char str[], int length){

    SqStatck S;
    InitStatck(S);

    for (int  i = 0; i < length; i++)
    {
        if(str[i] == '('  || str[i] == '{'  || str[i] == '[' ){
            Push(S,str[i])；
        }else{
            if(StackEmpty(S)){
                return false;
            }

            char topElem;

            Pop(S,topElem);

            if (str[i] == ')' && topElem != '('){
                return false;
            } 

             if (str[i] == ']' && topElem != '['){
                return false;
            } 

            if (str[i] == '}' && topElem != '{'){
                return false;
            } 


        }
        

    }
    return StackEmpty(S);

}

int main(int argc, char const *argv[])
{
    


    
    return 0;
}
