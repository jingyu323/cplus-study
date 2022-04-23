int (* func1(int arr[][3], int n))[3] 
{
    return &arr[n];
}

//使用尾置返回类型后
auto func1(int arr[][3], int n) -> int(*)[3] 
{
    return &arr[n];
}