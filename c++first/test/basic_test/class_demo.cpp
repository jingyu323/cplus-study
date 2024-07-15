#include <iostream> 

using namespace std;

//基类People
class People{
public:
    void setname(char *name);
    void setage(int age);
    void sethobby(char *hobby);
    char *gethobby();
    People(char*, int);
     People(){}; 
     virtual void display();
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
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}


class Address; 
//类的声明
class Student : public People{
protected:  //私有的
    // char *m_name;
    // int m_age;
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
    //定义构造函数
     Student(){}; 
    Student(const Student &stu);  //拷贝构造函数（声明）
    
};

//拷贝构造函数（定义）
Student::Student(const Student &stu){
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->m_score = stu.m_score;
     
   
    cout<<"Copy constructor was called."<< m_age <<endl;
}
 

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
// Student::Student(char *name, int age, float score){
//     m_name = name;
//     m_age = age;
//     m_score = score;
   
// }

Student::Student(char *name, int age, float score): People(name, age), m_score(score){ 
    m_total++;
    m_points += score;
     cout<<"default  constructor was called."<<endl;
}

//定义构造函数
// Student::Student(){
   
// }

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

//派生类Pupil
class Pupil: public Student {
public:
    void setranking(int ranking);
    void display();

    
  
private:
    int m_ranking;

};
 

void Pupil::setranking(int ranking){ m_ranking = ranking; }
void Pupil::display(){
    cout<<m_name<<"的年龄是"<<m_age<<"，考试成绩为"<<m_score<<"分，班级排名第"<<m_ranking<<"，TA喜欢"<<gethobby()<<"。"<<endl;
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

//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    void display();
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

//变长数组类
class Array{
public:
    Array(int len);
    Array(const Array &arr);  //拷贝构造函数
    ~Array();
public:
    int operator[](int i) const { return m_p[i]; }  //获取元素（读取）
    int &operator[](int i){ return m_p[i]; }  //获取元素（写入）
    int length() const { return m_len; }
private:
    int m_len;
    int *m_p;
};
Array::Array(int len): m_len(len){
    m_p = (int*)calloc( len, sizeof(int) );
}
// 深拷贝
Array::Array(const Array &arr){  //拷贝构造函数
    this->m_len = arr.m_len;
    this->m_p = (int*)calloc( this->m_len, sizeof(int) );
    memcpy( this->m_p, arr.m_p, m_len * sizeof(int) );
}
Array::~Array(){ free(m_p); }
//打印数组元素
void printArray(const Array &arr){
    int len = arr.length();
    for(int i=0; i<len; i++){
        if(i == len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
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



    Pupil pup;
    pup.setname("小明");
    pup.setage(15);
    pup.setscore(92.5f);
    pup.setranking(4);
    pup.sethobby("乒乓球");
    pup.display();

 printf("\n=================== People ==============\n");
    People *p = new People("王志刚", 23);
    p -> display();
    p = new Teacher("赵宏佳", 45, 8200);
    p -> display();


    People p1("王志刚", 23);
    Teacher t("赵宏佳", 45, 8200);
   
    People &rp = p1;
    People &rt = t;
   
    rp.display();
    rt.display();

 printf("\n=================== copy constract ==============\n");
    Student stu2 = stu;  //调用拷贝构造函数
    Student stu3(stu);  //调用拷贝构造函数
    stu2.display();
    stu3.display();
 printf("\n=================== Array Array ==============\n");

    Array arr1(10);
    for(int i=0; i<10; i++){
        arr1[i] = i;
    }
   
    Array arr2 = arr1;
    arr2[5] = 100;
    arr2[3] = 29;
   
    printArray(arr1);
    printArray(arr2);
    return 0;
}