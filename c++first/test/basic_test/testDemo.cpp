#include <vector> 
#include <iostream> 
#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <forward_list>
#include <c++/v1/list>
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
    
    printf("\n===================rbegin ==============\n");
     for (auto i = d.rbegin(); i < d.rend(); i++) {
        cout << *i << " ";
    }

    printf("\n===================insert ==============\n");
     //第一种格式用法
    d.insert(d.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    d.insert(d.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
   
    d.insert(d.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    d.insert(d.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    //调用push_front()向容器头部添加数据。
    d.push_front(2);//{2}
    //调用pop_front()移除容器头部的一个数据。
    d.pop_front();//{}
    //调用 emplace 系列函数，向容器中直接生成数据。
    d.emplace_back(2); //{2}
    d.emplace_front(3); //{3,2}
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }

     printf("\n===================list ==============\n");

    //创建空的 list 容器
    std::list<double> values;
    //向容器中添加元素
    values.push_back(3.1);
    values.push_back(2.2);
    values.push_back(2.9);
    cout << "values size：" << values.size() << endl;
    //对容器中的元素进行排序
    values.sort();
    //使用迭代器输出list容器中的元素
    for (std::list<double>::iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
    }
  printf("\n===================list begin  ==============\n");

    values.push_front(0);//{0,1,2,3}
    values.push_back(4); //{0,1,2,3,4}
    values.emplace_front(-1);//{-1,0,1,2,3,4}
    values.emplace_back(5);  //{-1,0,1,2,3,4,5}

    //第一种格式用法
    values.insert(values.begin() , 3);//{3,1,2}
    //第二种格式用法
    values.insert(values.end(), 2, 5);//{3,1,2,5,5}
    //第三种格式用法

    values.insert(values.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
    //第四种格式用法
    values.insert(values.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
   
    //emplace(pos,value),其中 pos 表示指明位置的迭代器，value为要插入的元素值
    values.emplace(values.end(), 6);//{-1,0,1,2,3,4,5,6}
    for (auto p = values.begin(); p != values.end(); ++p) {
        cout << *p << " ";
    }

    printf("\n===================list splice  ==============\n");

    //创建并初始化 2 个 list 容器
    list<int> mylist1{ 1,2,3,4 }, mylist2{10,20,30};
    list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2
   
    //调用第一种语法格式
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2:
                                 // it 迭代器仍然指向元素 2，只不过容器变为了 mylist1
    //调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
    mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
                                                    // mylist2: 2
                                                    // it 仍然指向元素 2
   
    //调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist.begin() 位置处                  
    mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
                                                                             //mylist2:1 10 20 30 3 4 2
   
    cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
    //输出 mylist2 容器中存储的数据
    cout << "mylist2:";
    for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
        cout << *iter << " ";
    }

      printf("\n===================list delete  ==============\n");

    values.remove(7);

     for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }
     //删除当前容器中首个元素
    values.pop_front();//{2,3,4}
   
    //删除当前容器最后一个元素
    values.pop_back();//{2,3}
   
    //清空容器，删除容器中所有的元素
    values.clear(); //{}
   
    for (auto begin = values.begin(); begin != values.end(); ++begin)
    {
        cout << *begin << " ";
    }

 printf("\n===================list mylist remove_if ==============\n");
     std::list<int> mylist{ 15, 36, 7, 17, 20, 39, 4, 1 };
    //删除 mylist 容器中能够使 lamba 表达式成立的所有元素。
    mylist.remove_if([](int value) {return (value < 10); }); //{15 36 17 20 39}
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;


printf("\n=================== map ==============\n");

    map<string, string> mymap;
    //向 mymap 容器中添加数据
    mymap["http://c.biancheng.net/c/"] = "C语言教程";
    mymap["http://c.biancheng.net/python/"] = "Python教程";
    mymap["http://c.biancheng.net/java/"] = "Java教程";
    //使用 map 容器的迭代器，遍历 mymap 容器，并输出其中存储的各个键值对
    for (map<string, string>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        //输出各个元素中的键和值
        cout << it->first << " => " << it->second << '\n';
    }



    printf("\n=================== pair ==============\n");
// 调用构造函数 1，也就是默认构造函数
    pair <string, double> pair1;
    // 调用第 2 种构造函数
    pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
    // 调用拷贝构造函数
    pair <string, string> pair3(pair2);
    //调用移动构造函数
    pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));
    // 调用第 5 种构造函数
    pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/"));  
   
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: "<< pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;

 printf("\n=================== map ==============\n");

    std::map<std::string, int>myMap1{std::make_pair("C语言教程",10),std::make_pair("STL教程",20)};

    std::map<std::string, int>newMap(myMap1);

    if (!newMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = newMap.begin(); i != newMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  

     printf("\n=================== map greater ==============\n");
    
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    std::map<std::string, std::string, std::greater<std::string>>myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http://c.biancheng.net/c/");
    myMap.emplace("Python教程", "http://c.biancheng.net/python/");
    myMap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size==" << myMap.size() << endl;
    //判断当前 myMap 容器是否为空
    if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  


 printf("\n=================== set  ==============\n");
     //创建空set容器
    std::set<std::string> myset;
    //空set容器不存储任何元素
    cout << "1、myset size = " << myset.size() << endl;
    //向myset容器中插入新元素
    myset.insert("http://c.biancheng.net/java/");
    myset.insert("http://c.biancheng.net/stl/");
    myset.insert("http://c.biancheng.net/python/");
    cout << "2、myset size = " << myset.size() << endl;
    //利用双向迭代器，遍历myset
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }

printf("\n=================== unordered_map  ==============\n");
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    cout << "umap 存储的键值对包括：" << endl;
    //遍历输出 umap 容器中所有的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << "<" << iter->first << ", " << iter->second << ">" << endl;
    }
    //获取指向指定键值对的前向迭代器
    unordered_map<string, string>::iterator iter = umap.find("Java教程");
    cout <<"umap.find(\"Java教程\") = " << "<" << iter->first << ", " << iter->second << ">" << endl;



printf("\n=================== unordered_map umap12  ==============\n");

//创建 umap 容器
    unordered_map<int, int> umap12;
    //向 umap 容器添加 50 个键值对
    for (int i = 1; i <= 50; i++) {
        umap12.emplace(i, i);
    }
    //获取键为 49 的键值对所在的范围
    auto pair = umap12.equal_range(49);
    //输出 pair 范围内的每个键值对的键的值
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first <<" ";
    }
    cout << endl;
    //手动调整最大负载因子数
    umap12.max_load_factor(3.0);
    //手动调用 rehash() 函数重哈希
    umap12.rehash(10);
    //重哈希之后，pair 的范围可能会发生变化
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first << " ";
    }


printf("\n=================== stack  ==============\n");

//构建 stack 容器适配器
    list<int> valuesl{ 1, 2, 3 };
    stack<int, list<int>> my_stack(valuesl);
    //查看 my_stack 存储元素的个数
    cout << "size of my_stack: " << my_stack.size() << endl;
    //将 my_stack 中存储的元素依次弹栈，直到其为空
    while (!my_stack.empty())
    {  
        cout << my_stack.top() << endl;
        //将栈顶元素弹栈
        my_stack.pop();
    }


printf("\n=================== deque  ==============\n");

// 定义并初始化为：1 3 5 2 4
std::deque<int> myDeque{ 1,3,5,2,4 };

myDeque.push_front(11);
myDeque.push_front(21);
myDeque.emplace_front(13);
 
// 降序排序示例。
std::sort(myDeque.begin(), myDeque.end(), std::greater<int>());
 
// 遍历容器所有元素示例。
for (int v : myDeque)
{
    // 输出 5 4 3 2 1
    std::cout << "v = " << v << std::endl;
} 

printf("\n=================== list iterator   ==============\n");

std::list<int> values222{1,2,3,4,5};
    //找到遍历的开头位置和结尾位置
    std::list<int>::iterator begin22 = --values222.end();
    std::list<int>::iterator end22 = --values222.begin();
    //开始遍历
    while (begin22 != end22)
    {
        cout << *begin22 << " ";
        --begin22;
    }

printf("\n=================== vector iterator  reverse_iterator  ==============\n");


// 创建并初始化一个 vector 容器
    std::vector<int> myvector{ 1,2,3,4,5,6,7,8 };
    //创建并初始化一个反向迭代器
    std::reverse_iterator<std::vector<int>::iterator> my_reiter(myvector.rbegin());//指向 8
    cout << *my_reiter << endl;// 8
    cout << *(my_reiter + 3) << endl;// 5
    cout << *(++my_reiter) << endl;// 7
    cout << my_reiter[4] << endl;// 3


printf("\n=================== vector iterator  back_insert_iterator  ==============\n");


//创建一个 vector 容器
    std::vector<int> foo;
    //创建一个可向 foo 容器尾部添加新元素的迭代器
    std::back_insert_iterator< std::vector<int> > back_it(foo);
    //将 5 插入到 foo 的末尾
    back_it = 5;
    //将 4 插入到当前 foo 的末尾
    back_it = 4;
    //将 3 插入到当前 foo 的末尾
    back_it = 3;
    //将 6 插入到当前 foo 的末尾
    back_it = 6;
    //输出 foo 容器中的元素
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << *it << ' ';

    printf("\n=================== vector iterator  front_insert_iterator  ==============\n");


    std::forward_list<int> foof;
    std::front_insert_iterator< std::forward_list<int> > front_itf = front_inserter(foof);
    //向 foo 容器的头部插入元素
    front_itf = 5;
    front_itf = 4;
    front_itf = 3;
    front_itf = 6;
    for (std::forward_list<int>::iterator it = foof.begin(); it != foof.end(); ++it)
        std::cout << *it << ' ';

        printf("\n=================== vector iterator  forward_list  ==============\n");


    forward_list<int> mylistff1{1,2,3,4};
    //it为前向迭代器，其指向 mylist 容器中第一个元素
    forward_list<int>::iterator itff1 = mylistff1.begin();

    for (itff1; itff1 != mylistff1.end(); ++itff1)
        std::cout << *itff1 << ' ';
   

}