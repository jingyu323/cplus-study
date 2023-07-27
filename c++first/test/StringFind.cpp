#include <stdio.h>
#include <stdlib.h>
#define MaxLength 255

#define MAXSTRLEN   255
#define OK          0
#define ERROR       1
#define TRUE        0
#define FAUSE       1
#define OVERFLOW    -2
#define FALSE       1

typedef int  Status ;


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

 
int StrLength(SString S) {
    return S.length;
}// StrLength

void StrInit(HString* s) {
	s->ch = NULL;
	s->length = 0;
}

/*堆串赋值*/
int StrAssign(HString* s, char* tval) {
//将字符串常量tval的值赋给堆串s
	int len = 0, i = 0;
	if (s->ch != NULL)
		free(s->ch);
	while (tval[i] != '\0')
		i++;
	len = i;
	if (len) {
		s->ch = (char*)malloc(len);				//申请空间
		if (s->ch == NULL)
			return FALSE;
		for (i = 0; i < len; i++)				//将字符串常量tval的值赋给堆串s
			s->ch[i] = tval[i];
	}
	else
		s->ch = NULL;
	s->length = len;
	return TRUE;
} 



 int SubString(SString *Sub, SString S, int pos, int len) {
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) return ERROR;
    for (int i = 1; i <= len; i++) (*Sub).ch[i] = S.ch[pos + i - 1];
    (*Sub).length = len; return OK;
}// SubString


int StrCompare(SString S, SString T) {
    if (S.length > T.length) return 1;
    else if (S.length < T.length) return -1;
    else {
        for (int i = 1; i <= S.ch[0]; i++) {
            if (S.ch[i] > T.ch[i]) return 1;
            else if (S.ch[i] < T.ch[i]) return -1;
        }
        return 0;
    }
}

// 再字符串中查找
int Index(SString S,SString T, int pos){
    if (pos > 0) {
        int n = StrLength(S), m = StrLength(T), i = pos;
        SString sub;
        while (i <= n - m + 1) {
            SubString(&sub, S, i, m);
            if (StrCompare(sub, T) != 0) ++i;
            else return i;
        }
    } 
    return 0;
}

int StrAssign(SString* S, char* chars) {
    int len; char* c;
      int index = 0;
    for (len = 0, c = chars; *c; len++) {
        // 指针的0位置是整个字符串，所以调整一下，让指针直接增加一位
        S->ch[len] = *c;
         printf("add index is %d \n", index);
    index ++;
        //   printf(" %s \n",c);
        //   printf(" %s \n",S);
        c++;        
    }
    S->length= len;
    return OK;
}// StrAssign
 

//由串 S 复制得串 T
int StrCopy(SString *T, SString S) {

    printf("99 -- %s \n",S);
    int index = 0;
    for (int i = 0; i < S.length; i++)
    {
        T->ch[i]=S.ch[i];
         printf("index is %d \n", index);
        index ++;
    }
    T->length = S.length;
   
    return OK;
}// StrCopy


Status StrDelete(SString* S, int pos, int len) {
    for (int i = 0; i <= (int)(*S).length - pos - len; i++) 
        (*S).ch[pos + i] = (*S).ch[pos + len + i];
    (*S).length-= len;
    return 0;
}
// 先删除 再增加
Status Replace(SString *S, SString T, SString V) {
    int pos = Index(*S, T, 1);
    if (!pos) return ERROR;
    StrDelete(S, pos, T.length);
    StrInsert(S, pos, V);
    return OK;
}// Replace

Status StrInsert(SString* S, int pos, SString T) {
    if ((*S).length + T.length> MAXSTRLEN) exit(OVERFLOW);
    SString tmp;
    for (int i = 1; i <= (*S).length - pos + 1; i++) tmp.ch[i] = (*S).ch[pos + i - 1];
    tmp.ch[0] = (*S).ch[0] - pos + 1;
    for (int i = 1; i <= T.length; i++) 
        (*S).ch[pos + i - 1] = T.ch[i];
    for (int i = 1; i <= tmp.length; i++) (*S).ch[pos + T.length + i - 1] = tmp.ch[i];
    (*S).length = (*S).length + T.length;
    return OK;
}


// 申请一段内存把 字符串放进去
/*堆串插入*/
int StrInsert(HString* s, int pos, HString* t) {
//在串s中下标为pos的字符之前插入串t
	int i;
	char* temp;
	if (pos < 0 || pos > s->length || s->length == 0)	//插入位置不合法
		return FALSE;
	temp = (char*)malloc(s->length + t->length);
	if (temp == NULL)
		return FALSE;
	for (i = 0; i < pos; i++)
		temp[i] = s->ch[i];						//串s前半段插入temp
	for (i = 0; i < t->length; i++)
		temp[i + pos] = t->ch[i];				//串t插入temp
	for (i = pos; i < s->length; i++)
		temp[i + t->length] = s->ch[i];			//串s后半段插入temp
	s->length += t->length;
	free(s->ch);
	s->ch = temp;								//temp赋给串s
	return TRUE;
} 

/*堆串输出*/
void Display(HString* s) {
	int i;
	if (s->length == 0)
		printf("空串！\n");
	else {
		for (i = 0; i < s->length; i++) {
			printf("%c", s->ch[i]);
		}
		printf("\n");
	}
} 


// 启用临时区域，把位置之前的元素放进去位置n之后的元素放进去 就合成一个新的字符数组
/*堆串删除*/
int StrDelete(HString* s, int pos, int n) {
	int i;
	char* temp;
	if (pos < 0 || pos>s->length - n)				//删除位置不合法
		return FALSE;
	temp = (char*)malloc(s->length - n);
	for (i = 0; i < pos; i++)
		temp[i] = s->ch[i];
	for (i = pos + n; i < s->length; i++)
		temp[i - n] = s->ch[i];
	s->length -= n;
	free(s->ch);
	s->ch = temp;
	return TRUE;
} 
int StrEmpty(SString S) {
    if (S.length) return FAUSE;
    else return TRUE;
}

int main(int argc, char const *argv[])
{
    
SString sss;
 
char* ss = "abcdefghijk"; // char 类型的字符擦

StrAssign(&sss,ss);

printf("%s \n",sss);
printf("ss len is :%d \n",sss.length);


SString copyStr;


StrCopy( &copyStr,sss);

printf("copy str test ,copyStr is : %s \n",copyStr);
printf("copy str test ,copyStr len is : %d \n",copyStr.length);
 
     
    return 0;
}
