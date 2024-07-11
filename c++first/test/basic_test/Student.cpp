
#include <iostream>
#include <string.h>
 

class Student   //声明类类名
{
private:      //声明私有成员
	int num;
	char name[20];
	char sex; 
public: 
    Student()  //自定义一个无参数的构造函数
	{
		num = 10;
        strcpy(name, "werwerwer");
		sex = '5';
	}

    Student(int num1,char sex1, char ssss[])  //自定义一个无参数的构造函数
	{
		num = num1;
        strcpy(name, ssss);
		sex = sex1;
	}


     //声明公有成员
	void display()
	{
		std::cout<<"num:"<<num<<std::endl;
		std::cout<<"name:"<<name<<std::endl;
		std::cout<<"sex:"<<sex<<std::endl; 
	}

    void swap(int &a, int &b)  //传入的参数为两个数的引用，这样就能通过改变引用值来改变实参的值。
{
	int temp;
	temp=a;
	a=b;
    b=temp;
    }
}; 

int main(int argc, char const *argv[])
{
    
    Student stu1;
    stu1.display();



    // char name[20]={'r','1','2','3'};
    char name[20]="woshixiaogou";
    Student stu2(23,'34',name);
    stu2.display();

    int a=10;
   	int &b=a;
	a=a*a;
	std::cout<<a<<b<<std::endl;
	b=b/5;
	std::cout<<a<<b<<std::endl;


    int i=3 , j=5;
    stu2.swap(i , j);
    std::cout << "i=" << i << "j=" << j << std::endl;



    return 0;
}
