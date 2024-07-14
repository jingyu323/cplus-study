#include<iostream>
using namespace std;

//基类Base
class Base{
public:
    void func();
    void func(int);
};
void Base::func(){ cout<<"Base::func()"<<endl; }
void Base::func(int a){ cout<<"Base::func(int)"<<endl; }

//派生类Derived
class Derived: public Base{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *str){ cout<<"Derived::func(char *)"<<endl; }
void Derived::func(bool is){ cout<<"Derived::func(bool)"<<endl; }

//间接基类A
class A{
public:
 A(int a);
//  A();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
// A::A( ){ }
//直接基类B
class B: virtual public A{  //虚继承
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
    cout<<"m_a="<<m_a<<", m_b="<<m_b<<endl;
}
//直接基类C
class C: virtual public A{  //虚继承
public:
    C(int a, int c);
public:
    void display();
protected:
    int m_c;
};

C::C(int a, int c): A(a), m_c(c){ }
void C::display(){
    cout<<"m_a="<<m_a<<", m_c="<<m_c<<endl;
}

//派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
public:
    void seta(int a){ m_a = a; }  //正确
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确
private:
    int m_d;
};

//  在最终派生类 D 的构造函数中，除了调用 B 和 C 的构造函数，还调用了 A 的构造函数，
// 这说明 D 不但要负责初始化直接基类 B 和 C，还要负责初始化间接基类 A。而在以往的普通继承中，派生类的构造函数只负责初始化它的直接基类，
// 再由直接基类的构造函数初始化间接基类，用户尝试调用间接基类的构造函数将导致错误。
D::D(int a, int b, int c, int d): A(a), B(90, b), C(100, c), m_d(d){ }
void D::display(){
    cout<<"m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}

int main(){
    Derived d;
    d.func("c.biancheng.net");
    d.func(true);
    // d.func();  //compile error
    d.func(10);  //compile error
    d.Base::func();
    d.Base::func(100);

    B b(10, 20);
    b.display();
   
    C c(30, 40);
    c.display();
    D d2(50, 60, 70, 80);
    d2.display();

    return 0;
}