#include <vector> 
#include <iostream> 
#include <array>
#include <deque>
using namespace std;
class testDemo
{
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};
int main()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);  
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);

    std::vector<int> demo{1,2};
    //第一种格式用法
    demo.insert(demo.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    demo.insert(demo.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
    std::array<int,3>test{ 7,8,9 };
    demo.insert(demo.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    demo.insert(demo.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
     //emplace() 每次只能插入一个 int 类型元素
    demo.emplace(demo.begin(), 33);
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }

     //初始化一个空deque容量
    deque<int>d;
    //向d容器中的尾部依次添加 1，2,3
    d.push_back(1); //{1}
    d.push_back(2); //{1,2}
    d.push_back(3); //{1,2,3}
    //向d容器的头部添加 0 
    d.push_front(0); //{0,1,2,3}
    //调用 size() 成员函数输出该容器存储的字符个数。
    printf("元素个数为：%d\n", d.size());
   
    //使用迭代器遍历容器
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    for (auto i = begin(d); i < end(d); i++) {
        cout << *i << " ";
    }

     printf("\n");

     auto first = d.cbegin();
    auto end = d.cend();
    //常量迭代器不能用来修改容器中的元素值
    //*(first + 1) = 6;//尝试修改容器中元素 2 的值
    //*(end - 1) = 10;//尝试修改容器中元素 5 的值
    //常量迭代器可以用来遍历容器、访问容器中的元素
    while(first<end){
        cout << *first << " ";
        ++first;
    }
    
}