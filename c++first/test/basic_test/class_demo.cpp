#include <iostream> 

using namespace std;
//类的声明
class Student{
private:  //私有的
    char *m_name;
    int m_age;
    float m_score;
    static int m_total;  //总人数
    static float m_points;  //总成绩
public:  //共有的
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
    static int getTotal();
    static float getPoints();
    //声明构造函数
    Student(char *name, int age, float score); 
};

int Student::m_total = 0;
float Student::m_points = 0.0;

//定义构造函数
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
    m_total++;
    m_points += score;
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
//定义静态成员函数
int Student::getTotal(){
    return m_total;
}
float Student::getPoints(){
    return m_points;
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

//  类调用
    int total = Student::getTotal();
    float points = Student::getPoints();
    cout<<"当前共有"<<total<<"名学生，总成绩是"<<points<<"，平均分是"<<points/total<<endl;


    return 0;
}