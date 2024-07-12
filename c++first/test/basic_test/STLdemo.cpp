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

    std::array<double, 10> values {};
    for (int i = 0; i < values.size(); i++)
    {
        
        cout << values[i] << " ";
    }
    printf("\n");

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
    
    


}