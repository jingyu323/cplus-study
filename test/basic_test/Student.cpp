

#include "Student.h"  //导入自己的头文件,Student.h是头文件名
using namespace std;

Student::Student(const string& name, int age, int no) {  //类函数的实行
    //注意在函数名前面加上 类名:: ,声明它的作用域
    //如果不加类名::，它就不是类函数了，是全局函数了
    cout << "执行构造函数了" << endl;
    m_name = name;
    m_age = age;
    m_no = no;

}

void Student::who(void) {
    cout << "我的名字是：" << m_name << endl;
    cout << "我的年龄是：" << m_age << endl;
    cout << "我的学号是：" << m_no << endl;
}