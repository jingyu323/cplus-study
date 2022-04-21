/**
 * @file test_point.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022

 *
 智能指针 
 */


#include<iostream>
#include<memory>
using namespace std;

int main(int argc, char const *argv[])
{
    
    

/**
 * 不要使用同一个原始指针构造 shared_ptr

创建多个 shared_ptr 的正常方法是使用一个已存在的shared_ptr 进行创建，而不是使用同一个原始指针进行创建
 * 
 */
    int *num = new int(23);
    std::shared_ptr<int> p1(num);

    std::shared_ptr<int> p2(p1);  // 正确使用方法
    std::shared_ptr<int> p3(num); // 不推荐
 
    std::cout << "p1 Reference = " << p1.use_count() << std::endl; // 输出 2
    std::cout << "p2 Reference = " << p2.use_count() << std::endl; // 输出 2
    std::cout << "p3 Reference = " << p3.use_count() << std::endl; //

// 当我们创建 shared_ptr 对象而不分配任何值时，它就是空的；普通指针不分配空间的时候相当于一个野指针，指向垃圾空间，且无法判断指向的是否是有用数据
    std::shared_ptr<string> ptr3;
    if(!ptr3)
        std::cout<<"Yes, ptr3 is empty" << std::endl;
    if(ptr3 == NULL)
        std::cout<<"ptr3 is empty" << std::endl;
    if(ptr3 == nullptr)
        std::cout<<"ptr3 is empty" << std::endl ;

//         不要用栈中的指针构造 shared_ptr 对象
// shared_ptr 默认的构造函数中使用的是delete来删除关联的指针，所以构造的时候也必须使用new出来的堆空间的指针

  int x = 12;
   std::shared_ptr<int> ptr(&x);

//    建议使用 make_shared
// 为了避免以上两种情形，建议使用make_shared()<>创建 shared_ptr 对象，而不是使用默认构造函数创建


std::shared_ptr<int> ptr_1 = make_shared<int>();
std::shared_ptr<int> ptr_2 (ptr_1);

 
    std::cout << "ptr_1 Reference = " << ptr_1.use_count() << std::endl; // 输出 2
    std::cout << "ptr_2 Reference = " << ptr_2.use_count() << std::endl; // 输出 2 

    return 0;
}
