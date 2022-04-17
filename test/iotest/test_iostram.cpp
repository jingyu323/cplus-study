#include <iostream>
using namespace std;

void process_input(  ){
    cout << "process_input " << endl;
     char name[50];
    cin >> name;
    cout << "name" << name << endl;
}

int main(int argc, char const *argv[])
{
    auto old_status = cin.rdstate();
    cin.clear();
    cout << "old_status " << old_status << endl;

    process_input( );

    cin.setstate(old_status);
     
    return 0;
}



// void process_input(cin){

//     cin >> name;
//    cout << "out " << name << endl;

// }


/**
 * 流的状态
 * badbit 发生从错误无法恢复
 * failbit  发生错误还可以修复
 * eofbit 
 * gootbit  值为0 
 * 
 * C++语言不直接处理输入输出，而是通过一族定义在标准库中的类型来处理IO。这些类型支持从设备读取数据、向设备写入数据的io操作，设备可以是文件、控制台窗口等。还有一些类型允许内存io,即，从string读取数据，向string写入数据。
●istream (输入流)类型，提供输入操作。
●ostream (输出流)类型，提供输出操作。
●cin,一个istream对象，从标准输入读取数据。
●cout，一个ostream对象，向标准输出写入数据。
●cerr,一个ostream对象，通常用于输出程序错误消息，写入到标准错误。
●>>运算符，用来从一个istream对象读取输入数据。
●<<运算符，用来向一个ostream对象写入输出数据。
●getline函数，从一个给定的istream读取一行数据，存入一个给定的string对象中。 
 */