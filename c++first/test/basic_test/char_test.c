#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */

    char* ss = "abcdefghijk";

    printf("%s \n",ss);
    int len; char* c;
    for (len = 0, c = ss; *c; len++) {
         printf("%d %s  %p \n",len,c,*c);
         c++;
    }


    char *str = "abcdef";
    printf("9999999 ---  %s,%p\n", ++str,str);


//定义一维数组：
	float arr[] = { 3.14f,99.9f,66.5f,0.0f };
 
	//定义指针变量：
	float* p = arr; //把数组名（首地址）放进指针中
 
	//计算数组元素个数：
	int sz = sizeof(arr) / sizeof(arr[0]);//元素个数
 
	//使用 for循环 和 指针变量 打印数组内容：
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//使用 解引用符号* 获取指针内容
		printf("%f ", *p);
		//获取一位后就调整一次指针，把指针移向下一位
		p++;
	}
 


    return 0;
}
