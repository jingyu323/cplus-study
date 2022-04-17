#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    
string name;
	int age;
	ifstream infile;
	infile.open("user.dat", ios::in | ios::binary);


    while (1) {
		infile >> name;
		if (infile.eof()) { //判断文件是否结束
			break;
		}
		cout << name << "\t";
        
       // 跳过中间的制表符
		char tmp;
		infile.read(&tmp, sizeof(tmp)); 

		//infile >> age; //从文本文件中读取整数, 使用这个方式
		infile.read((char*)&age, sizeof(age));
		cout << age << endl;  //文本文件写入 
        
        }

    return 0;
}

/**
 * 
