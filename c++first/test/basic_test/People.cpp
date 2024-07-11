#include<iostream>
using namespace std;

//基类People
class People{
public:
    void setname(char *name);
    void setage(int age);
    void sethobby(char *hobby);
    char *gethobby();
    void show();
protected:
    char *m_name;
    int m_age;
private:
    char *m_hobby;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
void People::sethobby(char *hobby){ m_hobby = hobby; }
char *People::gethobby(){ return m_hobby; }
void People::show(){
    cout<<"嗨，大家好，我叫"<<m_name<<"，今年"<<m_age<<"岁"<<endl;
}

//派生类Student
class Student: public People{
public:
    void setscore(float score);
    void show();  //遮蔽基类的show()
protected:
    float m_score;
};
void Student::setscore(float score){ m_score = score; }
void Student::show(){
    cout<<m_name<<"ddddddd 的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
//派生类Pupil
class Pupil: public Student{
public:
    void setranking(int ranking);
    void display();
     void show();  //遮蔽基类的show()
private:
    int m_ranking;
};
void Pupil::setranking(int ranking){ m_ranking = ranking; }
void Pupil::display(){
    cout<<m_name<<"的年龄是"<<m_age<<"，考试成绩为"<<m_score<<"分，班级排名第"<<m_ranking<<"，TA喜欢"<<gethobby()<<"。"<<endl;
}
void Pupil::show(){
    cout<<m_name<<"qqqqqqqqqqqq的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

// 基类成员函数和派生类成员函数不构成重载
int main(){
    Pupil pup;
    pup.setname("小明");
    pup.setage(15);
    pup.setscore(92.5f);
    pup.setranking(4);
    pup.sethobby("乒乓球");
    pup.display();
    pup.show();
    pup.Student::show();
    pup.People::show();
    return 0;
}