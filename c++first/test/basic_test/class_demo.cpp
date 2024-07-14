#include <iostream> 

using namespace std;
//类的声明
class Student{
private:  //私有的
    char *m_name;
    int m_age;
    float m_score;
public:  //共有的
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
    //声明构造函数
    Student(char *name, int age, float score); 
};

//定义构造函数
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
//成员函数的定义
void Student::setname(char *name){
    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
int main(){
//  无参构造函数
// Student stu 直接创建 添加了有参构造之后
    //在栈上创建对象
    Student stu("小明", 15, 92.5f);
    stu.setname("小明");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();
    //在堆上创建对象
    Student *pstu = new Student("李华", 16, 96);
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();
    return 0;
}