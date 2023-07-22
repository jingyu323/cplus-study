#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct 
{
    char  data[MaxSize];
    int top;
} SqStatck ;

void InitStatck(SqStatck &S){
    S.top = -1;
}


bool StackEmpty(SqStatck s){
    if(s.top == -1){
        return true;
    }else{
        return false;
    }

}

bool Push(SqStatck &S, char x){

// 栈满了
    if(S.top == MaxSize -1){
        return false;
    }
    S.top = S.top +1;

    S.data[S.top] = x;
    return true;

}

bool Pop(SqStatck  &s, char &x){
    if(s.top  == -1 ){
        return  false;
    }
    x  = s.data[s.top];
    s.top = s.top -1;
    return true;

}

bool bracketCheck(char str[], int length){

    SqStatck S;
    InitStatck(S);

    for (int  i = 0; i < length; i++)
    {
        if(str[i] == '('  || str[i] == '{'  || str[i] == '[' ){
            Push(S,str[i]);
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
    
    char str1[] = {'{','}','(',')'};

    bool res =  bracketCheck(str1,4);
    printf("%d\n",res);

bool b = true;

printf("%d\n",b);

bool c = false;

printf("%d\n",c);

    return 0;
}
