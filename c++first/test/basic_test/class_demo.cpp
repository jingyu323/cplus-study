#include <iostream>
using namespace std;

class Student{
public:
    char *name;
    int age;
    float score;
    void say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }
};

int main(){
    // 内存创建
    Student stu;
    stu.name = "小明";
    stu.age = 152;
    stu.score = 922.5f;
    stu.say();
// 堆创建
    Student *pStu = new Student;
    pStu -> name = "小明";
    pStu -> age = 15;
    pStu -> score = 92.5f;
    pStu -> say();
    delete pStu;  //删除对象
    return 0;
}