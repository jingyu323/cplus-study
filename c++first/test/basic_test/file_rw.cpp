#include <iostream>
#include <fstream>
using namespace std;
int main() {
    const char *url ="http://c.biancheng.net/cplus/";
    //创建一个 fstream 类对象
    fstream fs;
    //将 test.txt 文件和 fs 文件流关联
    fs.open("test.txt", ios::out);
    //向test.txt文件中写入 url 字符串
    fs.write(url, 30);
    fs.close();


    ifstream inFile;
    inFile.open("test.txt", ios::in);
    if (inFile)  {
           inFile.close();
        cout << "test.txt   exist" << endl;

    }//条件成立，则说明文件打开成功
     
    else
        cout << "test.txt doesn't exist" << endl;
     ofstream oFile;
    oFile.open("test1.txt", ios::out);
    if (!oFile)  //条件成立，则说明文件打开出错
        cout << "error 1" << endl;
    else
        oFile.close();
    oFile.open("test2.txt", ios::out | ios::in);
    if (oFile)  //条件成立，则说明文件打开成功
        oFile.close();
    else
        cout << "error 2" << endl;
    fstream ioFile;
    ioFile.open("test3.txt", ios::out | ios::in | ios::trunc);
    if (!ioFile)
        cout << "error 3" << endl;
    else
        ioFile.close();

    return 0;
}