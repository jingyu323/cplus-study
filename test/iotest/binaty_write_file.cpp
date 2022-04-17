#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
   string name;
	int age;
	ofstream outfile;
	outfile.open("user.dat", ios::out | ios::trunc | ios::binary);
while (1) {
		cout << "请输入姓名: [ctrl+z退出] ";
        cin >> name;
		if (cin.eof()) { //判断文件是否结束
			break;
		}

        outfile << name << "\t";

		cout << "请输入年龄: ";
		cin >> age;  
		//outfile << age << endl;  //会自动转成文本方式写入
		outfile.write((char*)&age, sizeof(age)); 
        
    }

    // 关闭打开的文件
	outfile.close();

    return 0;
}
