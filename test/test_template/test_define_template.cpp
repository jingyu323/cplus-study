
/**
 * @brief 
 * 什么是模板？ 公共的方法或者类定义一个公共的 但
 * 
 * 作用是什么？
 * 
 * 
 */
//类模版语法
#include<iostream>
using namespace std;

/*
类模板和函数模板深入理解
1.编译器并不是把函数模板处理成能处理任何类型的函数
2.编译器从函数模板通过具体类型产生不同的函数
3.编译器会对函数模板进行两次编译
4.在声明的地方对模板代码进行编译
5.在调用的地方对参数替换后的代码进行编译

对于类模板原理也是相同
强调2点：
①类模版或者函数模板是c++编译器根据调用对象的类型参数生成对应的类或者函数
也就是说不同的类型参数会产生不同的类和函数
②类模板或者函数模板会进行2次编译
*/

template<typename T>
class Rectangle {
public:
    Rectangle(T a,T b){
        this->weight = a;
        this->height = b;
    }
    T GetW(){
        return this->weight;
    }
    void SetA(T a);
    Rectangle GetSelf();
private:
    T weight;
    T height;
};

//在类外面实现类中的成员函数
template<typename T>//模板声明
void Rectangle<T>::SetA(T a){
    this->weight = a;
}

//类模板对象做参数也必须加上参数列表
template<typename T>
void PrintA(Rectangle<T> a){
    cout << "我PrintA被调用了！" << endl;
}

template<typename T>
Rectangle<T> Rectangle<T>::GetSelf(){
    return *this;
}

void PrintB(Rectangle<int> a){
    cout << "我PrintB被调用了！" << endl;
}

//类模板的继承
template<typename T>
class Square :public Rectangle<T>{
public:
    Square(T a) :Rectangle<T>(a, a){}
};

class Square2 :public Rectangle<int>{
public:
    Square2(int a) :Rectangle<int>(a, a){}
};
/*
结论：类模板实现了对数据类型的抽象化，导致c++编译器无法无法确定类对象的大小，
所以在任何地方使用类模板，要么加上模板声明，要是具体化类模板
对于类模板而言  有具体的参数列表才是一个真正的类  
Rectangle，c++编译器不认为他是一个类
Rectangle<int> ，c++编译器认为他是一个类
*/
void ProtectA(){
    //Rectangle r1;
    //报错  error C2955: “Rectangle”: 使用 类 模板 需要 模板 参数列表
    /*
    本质上的原因是：类本身是一个对象的抽象，声明类的时候并不会分配内存（只有定义对象的时候才会）
    类模板又是在类的基础上进一步对数据类型进行抽象化
    c++编译器无法确定一个类对象的大小
    */
    Rectangle<int> r2(1, 2);
    /*
    类模板定义对象时，必须加类型参数列表，不然无法确定对象大小
    */
    PrintA(r2);
    PrintB(r2);
}

void ProtectB(){
    Square<int> sq1(1);
    Square2 sq(2);
} 

int main(){
    
    system("pause");
}