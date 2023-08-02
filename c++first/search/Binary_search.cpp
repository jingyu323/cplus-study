

//  折半查找
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
     int *elem;
     int tableLen;
} SSTable;



int Binary_search(SSTable L , int key){

    int low =0,hight=L.tableLen-1,mid;
    while (low <= hight)
    {
        mid = (low + hight) /2;

        if(L.elem[mid] == key){
            return mid;

        }else if (L.elem[mid] > key)
        {
            hight = mid -1;
        }else{
            low = mid +1;
        }
        
    }
    


    return -1;

}