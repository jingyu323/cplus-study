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
 关键字就是 struct 或者class，区别点是默访问权限不同，
 使用class：第一个访问修饰符之前的成员都是private 的
 使用struct：第一个访问修饰符之前的成员都是public的
### 友元函数

### 文件读写

要实现以二进制形式读写文件，<< 和 >> 将不再适用，需要使用 C++ 标准库专门提供的 read() 和 write() 成员方法。其中，read() 方法用于以二进制形式从文件中读取数据；write() 方法用于以二进制形式将数据写入文件

写入文件会转换到文本方式写入
需要使用write(写)吧整形转换到char类型，进行写入



# C 语言
getchar() & putchar() 函数
int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。

gets() & puts() 函数
char *gets(char *s) 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF。

int puts(const char *s) 函数把字符串 s 和一个尾随的换行符写入到 stdout。

scanf() 和 printf() 函数
int scanf(const char *format, ...) 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。

int printf(const char *format, ...) 函数把输出写入到标准输出流 stdout ，并根据提供的格式产生输出。


