
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,6,4,8,9,1,3};
	int i = 0;
	i = sizeof(arr) / sizeof(arr[0]);//数组总字节（36）除以单个成员的字节（4）
	printf("%d", i);//i=9
	return 0;

}