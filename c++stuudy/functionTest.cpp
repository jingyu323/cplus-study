#include<iostream>
using namespace std;

/*
如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的形式参数。

形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁
递参数的方式:
    1.传值调用
    2.指针调用
    3.引用调用

*/

// 函数定义 传值调用 
void swap(int x, int y)
{
   int temp;
 
   temp = x; /* 保存 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y */
  
   return;
}

// 函数定义  指针调用 
void swappoint(int *x, int *y)
{
   int temp;
   temp = *x;    /* 保存地址 x 的值 */
   *x = *y;        /* 把 y 赋值给 x */
   *y = temp;    /* 把 x 赋值给 y */
  
   return;
}


// 引用调用  函数定义
void swapaddr(int &x, int &y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
  
   return;
}

int main(){


     // 局部变量声明
   int a = 100;
   int b = 200;

   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;

   /* 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址 
    * &b 表示指向 b 的指针，即变量 b 的地址 
    */
   swappoint(&a, &b);

   cout << "指针调用 交换后，a 的值：" << a << endl;
   cout << "指针调用  ，b 的值：" << b << endl;

    // 参数调用
   swap(a,  b);

   cout << "参数 交换后，a 的值：" << a << endl;
   cout << "参数  ，b 的值：" << b << endl;   

    // 引用调用
    swapaddr(a, b);

    cout << "引用调用 交换后，a 的值：" << a << endl;
   cout << "引用调用  ，b 的值：" << b << endl;  

}