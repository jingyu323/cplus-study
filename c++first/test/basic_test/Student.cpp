
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

void func(void){
    std::cout << "test" << std::endl;
}

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

   
    int *p = &a;
    int& r = a;

    // 1. 指针的指针
    // =右边变量类型 * 变量名 = &变量
    // *pp == &p, **pp == 10;
    int* * pp = &p; 
    
    // 2. 引用的指针 (编译报错)
    // 引用在c++ 中是没有内存的，也就没有地址
    // int& * pr = &r;
    int* pr = &r; //不是引用的指针，只是一个普通的指针,相当于 int* pr = &a;

    // 3. 指针的引用(指针的别名)
    // =右边的类型 & 应用名 = 变量名
    // *rp == 10;
    int* & rp = p;

    // 4. 引用的引用 (编译报错)
    // int& & rr = r;
    int& rr = r; // 不是引用的引用，仅仅是普通的引用，相当于 int& rr = a;

   
    int x = 10, y = 20, z = 30;

    // 5. 可以定义指针数组
    int *parr[3] = {&x, &y, &z};

    // 6. 不可以定义引用数组
    // 数组中元素的内存对应的地址是连续的，而引用是不占内存的，没有对应的地址 
    // int& rarr[3] = {x, y, z};

    // 7. 数组引用是可以的
    int arr[3] = {1 ,2, 3};
    // 给arr数组起别名rarr， 类型是int[3]
    int (&rarr)[3] = arr;

    // 8. 函数的指针
    void(* p_func)(void) = func;
    p_func();

    // 9. 函数的引用
    void(& r_func)(void) = func;
    r_func(); 

    return 0;
}
