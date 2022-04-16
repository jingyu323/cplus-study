#include <iostream>
using namespace std;

class Student  //类的声明
    //包括函数的声明，成员的声明
{
public:
    Student(const string& name, int age, int no);//构造函数的声明
    void who(void);  //自定义函数的声明

private:
    string m_name;
    int m_age;
    int m_no;

};