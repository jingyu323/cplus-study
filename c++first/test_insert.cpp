#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct   
{
    int data[MaxSize];
    int length;
} SqlList ;

void InitList(SqlList &L) {

            for (int i = 0; i < 6; i++)
    {
         L.data[i] = i+8;
    }
   
  L.length =  6; 
}

void ListInsert( SqlList &L,int i ,int e ){

    for(int j = L.length ;j>= i;j--){
        L.data[j] = L.data[j-1];
    }

    L.data[i-1] = e;
    L.length++;


}


bool ListDelet(SqlList &L,int i ,int &e ){

    if(i < 1 || i > L.length){
        return false;
    }
    e = L.data[i-1];

    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length -- ;

    return true;


}

int main(int argc, char const *argv[])
{
    SqlList L;

    InitList(L);
    

    ListInsert(L,3,3);

     for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n",i,L.data[i]);
    }

  int e =3;
    ListDelet(L,3,e);
    printf("\n");
     for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n",i,L.data[i]);
    }

    return 0;
}
