## C++ 学习总结
#### 1.指针和引用

 ##### 1.1 指针
 1.可以指向空
 2.指针可以在任何时候指向到另一个对象。
 3.指针可以在任何时间被初始化。
  int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 ##### 1.2 引用
 1.不可以指向空值
 2.一旦引用被初始化为一个对象，就不能被指向到另一个对象
 3.引用必须在创建时被初始化
 int&  r = i;
 ### exception
 * 1.runtime_error
 * 2.range_error
 * 3.excetion common error
 * 4.overflow_error :runtime error compute overflow
 * 5.logic_error : programe logic error
 * 6.invalid_argument: invalid arg

 ### C++ 的main函数
 没有添加return 是因为编译器自动会添加
 ### 创建一个类
 关键字就是 struct 或者class，区别点是默访问权限不同
 