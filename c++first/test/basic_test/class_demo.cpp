#include <iostream> 

using namespace std;

class Address; 
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
    void show(Address *addr);
};

//声明Address类
class Address{
public:
    Address(char *province, char *city, char *district);
public:
    //将Student类声明为Address类的友元类
    friend class Student;
private:
    char *m_province;  //省份
    char *m_city;  //城市
    char *m_district;  //区（市区）
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

void Student::show(Address *addr){
    cout<<m_name<<"的年龄是 "<<m_age<<"，成绩是 "<<m_score<<endl;
    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
}

//实现Address类
Address::Address(char *province, char *city, char *district){
    m_province = province;
    m_city = city;
    m_district = district;
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
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);
    //在堆上创建对象
    Student *pstu = new Student("李华", 16, 96);
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu -> show(paddr);

//  类调用
    int total = Student::getTotal();
    float points = Student::getPoints();
    cout<<"当前共有"<<total<<"名学生，总成绩是"<<points<<"，平均分是"<<points/total<<endl;
    printf("\n=================== string    ==============\n");

    string s1, s2, s3,s4;
    s1 = s2 = s3 = "1234567890";
    s2.erase(5);
    s3.erase(5, 3);
    cout<< s1 <<endl;
    cout<< s2 <<endl;
    cout<< s3 <<endl;

    s4 = s1.substr(6, 6);
    cout<< s1 <<endl;
    cout<< s4 <<endl; 
    printf("\n=================== string  find  ==============\n");



    string s5 = "first second third";
    string s6 = "second";
    int index = s5.find(s6,5);
    if(index < s5.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;

    return 0;
}