#include <stdio.h>
#include <stdlib.h>
#define MaxLength 255

typedef struct 
{
    char ch[MaxLength];
    int length;
} SString,*String;



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


bool StrAssign(SString  *S, char* chars) {
    int len; char* c;
    for (len = 0, c = chars; *c; len++, c++) {
        (*S).ch[len + 1] = *c;
    }
    (*S).ch[0] = len;
    return true;
}// StrAssign


int Index(SString s,SString T){
    
return 0;
}


int main(int argc, char const *argv[])
{
    
String sss;  

char ss = "wewewe";

StrAssign(sss,&ss);

 
 printf("%s",sss);


     
    return 0;
}
