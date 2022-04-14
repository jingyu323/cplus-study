#include <iostream>

using namespace std;

int main()
{
    cout << "ddd" << endl;

int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
 
 //  如果定义了指针，输出指针便利的话打印出来的就是指针指向的内存的值，如果只是不带星的变量则是指针的地址

 // 指针的初始化是要指定变量地址的
 //  
   return 0;

}