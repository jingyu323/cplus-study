#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief 
 * 指定格式写文件:
使用 < stringstream>
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    string name;
	int age;
	ofstream outfile;
	outfile.open("user.txt", ios::out  );
    while (1) {
		cout << "[ctrl+z退出]" << endl;
		cout << "请输入姓名: ";
		cin >> name;
		if (cin.eof()) { //判断文件是否结束
            cout << "break ";
			break;
		}
cout << name<< ",,," << endl;
		cout << "请输入年龄: ";
		cin >> age; 
      

        stringstream s;
		s << "name:" << name << "\t\tage:" << age << endl;


        cout << "7777777777777请输入年龄: " << s.str(); 
		outfile << s.str()<< " ===999";

    }
   cout << " -- close" << endl;
// 关闭打开的文件
	outfile.close();

 

    system("pause");
    return 0;
}
