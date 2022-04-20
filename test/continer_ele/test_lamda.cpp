
#include <iostream>


/**
 * @brief 
 * 
 * lambda表达式基本语法如下：

[ 捕获 ] ( 形参 ) -> ret { 函数体 };
 * 
 * 
 */
int main(int argc, char const *argv[])
{
    /* code */

     auto atLambda = [] {std::cout << "hello world" << std::endl;};


 auto print = [](int s) {std::cout << "value is " << s << std::endl;};

int x = 10;
     
 print(6);

atLambda(); // 调用才会执行


 auto lambAdd = [](int a, int b) ->int { return a + b;};
int iSum = lambAdd(10, 11);
    print(iSum);

auto lambAdd1 = [x](int a) { return a + x;};
    auto lambAdd2 = [&x](int a, int b) { return a + b + x;};
    auto iSum1 = lambAdd1(10);
    auto iSum2 = lambAdd2(10, 11);
    print(iSum1);
    print(iSum2);



    return 0;
}
