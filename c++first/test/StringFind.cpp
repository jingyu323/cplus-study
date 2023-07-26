#include <stdio.h>
#include <stdlib.h>
#define MaxLength 255

typedef struct 
{
    char ch[MaxLength];
    int length;
} SString;



typedef struct 
{
    char *ch;
    int length;
} HString;

HString S1;

 void InitHString(){
    S1.ch = (char *) malloc(MaxLength * sizeof(char));
    S1.length = 0;
 }

int Index(SString s,SString T){
    

}


int main(int argc, char const *argv[])
{
    
SString sss;
sss.ch ="sd";

char site[] = "RUNOOB";


     
    return 0;
}
