#include<iostream>
using namespace std;

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

const int  HEIGHT  = 5;

// 函数定义  必须放在调用之前 否则就会报错，也就是说声明了可以不用实现
//int func();  声明函数

int add(int a ,int b );


int main()
{
    int a = 5;
    int b = 8;
    // cout<< a << b << endl;
    cout << "length --->>>"<<LENGTH << endl;

    cout <<"a  new linee -->> " <<NEWLINE ;

     cout<<"Hello world!"<< add( a , b ) << endl;
    cout<<"constans  height ->>> "<< HEIGHT<< endl;   

    if(a< b){
      cout<< "a < b";
    }else{
      cout<< "a  > b";
    }

   return 0;
}





int add(int a ,int b )
{
    return a + b;
}

//函数 实现
// int func()
// {
//     return 0;
// }

/*
 * 1.当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。定义全局变量时，系统会自动初始化为下列值
 * 
 * 定义常量
    在 C++ 中，有两种简单的定义常量的方式：

    使用 #define 预处理器。
  使用 const 关键字。
 * 
 * 
 * 
 */

