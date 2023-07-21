#define MaxSize 10
typedef struct   
{
    int *data;
    int length;
    int maxSize;
} SqlList ;

void InitListArr(SqlList &L);