#include <iostream>
#include <fstream> 
using namespace std;


/**
 * @brief 
 * 
 * 常用的值如下：
　　ios::app：　　　以追加的方式打开文件
　　ios::ate：　　　文件打开后定位到文件尾，ios:app就包含有此属性
　　ios::binary：　以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文
　　ios::in：　　　 文件以输入方式打开(文件数据输入到内存)
　　ios::out：　　　文件以输出方式打开(内存数据输出到文件)
　　ios::nocreate： 不建立文件，所以文件不存在时打开失败
　　ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败
　　ios::trunc：　　如果文件存在，把文件长度设为0 
 * 
 * @return string 
 */
string process_input(  ){
    cout << "process_input " << endl;
     char name[50];
    cin >> name;
    cout << "name" << name << endl;
    return name;
}

int main(int argc, char const *argv[])
{
    auto old_status = cin.rdstate();
    cin.clear();
    cout << "old_status " << old_status << endl;

    string input_name =  process_input( );

    cin.setstate(old_status);

    cout<<"hi!"<<endl;//输出hi和换行，然后刷新缓冲区
    cout<<"hi!"<<flush;//输出hi，然后刷新缓冲区，不附加任何额外字符
    cout<<"hi!"<<ends;//输出hi和空字符，然后刷新缓冲区
    ofstream out;
    out.open("file1",ofstream::out | ofstream::app);
    if(!out.fail()){

        out << input_name ;

    } 
    out.close();

 

 
fstream   reader;
reader.open("file1",ofstream::in );
 cout << "readfile start"  << endl;

char buf[1021]={0};
while(reader.getline(buf,sizeof(buf)))
{
    std::cout<<buf<<std::endl;
} 
reader.close();
     
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