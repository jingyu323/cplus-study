//遍历 vector 容器。
#include <iostream>
//需要引入 vector 头文件
#include <vector>
#include <list>
#include <array>
using namespace std;

int main()
{


    vector<int> v{1,2,3,4,5,6,7,8,9,10}; //v被初始化成有10个元素
    cout << "第一种遍历方法：" << endl;
    //size返回元素个数
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] <<" "; //像普通数组一样使用vector容器
    //创建一个正向迭代器，当然，vector也支持其他 3 种定义迭代器的方式
    
       cout << endl << "第二种遍历方法：" << endl;
        vector<int>::iterator i;
    //用 != 比较两个迭代器
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
         cout << endl << "第三种遍历方法：" << endl;
    for (i = v.begin(); i < v.end(); ++i) //用 < 比较两个迭代器
        cout << *i << " ";
   
       cout << endl << "第四种遍历方法：" << endl;
    i = v.begin();
    while (i < v.end()) { //间隔一个输出
        cout << *i << " ";
        i += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }


    //创建一个 v list容器
    list<int> v1{78,99,66,3,4,5,6,7,8,9,10};
    //创建一个常量正向迭代器，同样，list也支持其他三种定义迭代器的方式。
    list<int>::const_iterator ci;

    for(ci = v1.begin(); ci!= v1.end(); ++ci)
        cout << *ci << " ";
 printf("\n");
    std::array<double, 10> values {};
    for (int i = 0; i < values.size(); i++)
    {
        
        cout << values[i] << " ";
    }
    printf("\n");


    int h = 1;
    auto first = values.begin();
    auto last = values.end();
    //初始化 values 容器为{1,2,3,4,5}
    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }

    //  first = values.begin();
    // while (first != last)
    // {
    //     cout << *first << " ";
    //     ++first;
    // }


    //   printf("\n");
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            cout << *val << " ";
        }
    }
        printf("\n");


// 初始化
    std::array<double, 10> values2 {0.5,1.0,1.5,2.0};
        for (int i = 0; i < values2.size(); i++)
    {
        cout << values2[i] << " ";
    }
     printf("\n");

    //初始化一个空vector容量
    vector<char>value;
    //向value容器中的尾部依次添加 S、T、L 字符
    value.push_back('S');
    value.push_back('T');
    value.push_back('L');
    //调用 size() 成员函数容器中的元素个数
    printf("元素个数为：%d\n", value.size());
    //使用迭代器遍历容器
    for (auto i = value.begin(); i < value.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    //向容器开头插入字符
    value.insert(value.begin(), 'C');
    cout << "首个元素为：" << value.at(0) << endl;
    for (auto i = value.begin(); i < value.end(); i++) {
        cout << *i << " ";
    }


    vector<int>values12{1,2,3};
    cout << "values 容器首个元素的地址：" << values12.data() << endl;
    auto first12 = values12.begin();
    auto end12 = values12.end();
    //增加 values 的容量
    values12.reserve(20);
    cout << "values 容器首个元素的地址：" << values12.data() << endl;
    first12 = values12.begin();
    end12 = values12.end();
    while (first12 != end12) {
        cout << *first12 ;
        ++first12;
    }
    
    cout << "values 首元素为：" << values12.front() << endl;
    cout << "values 尾元素为：" << values12.back() << endl;
    //修改首元素
    values12.front() = 10;
    cout <<"values 新的首元素为：" << values12.front() << endl;
    //修改尾元素
    values12.back() = 20;
    cout << "values 新的尾元素为：" << values12.back() << endl;

    //输出容器中第 3 个元素的值
    cout << *(values12.data() + 2) << endl;
    //修改容器中第 2 个元素的值
    *(values12.data() + 1) = 10;
    cout << *(values12.data() + 1) << endl;

    //从下标 0 一直遍历到 size()-1 处
    for (int i = 0; i < values12.size(); i++) {
        cout << values12[i] << " ";
    }


}