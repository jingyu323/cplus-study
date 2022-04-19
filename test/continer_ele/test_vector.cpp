
/**
 * @brief 
 * vector 可变数组 支持随机访问在尾部之外的位置插入或者删除元素很慢
 * 
 * deque 双端队列 支持随即访问 在头尾位置的插入删除很快
 * 
 * list 双向链表 在list任何位置都很快
 * forward——list 单向链表 只能顺序访问
 * array 固定大小的数组 支持随即快速访问，不能添加或者删除元素
 * 
 * string 只能存储字符，随即访问快 在尾部插入删除速度快
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <fstream> 

 
#include <sstream>
#include <string>

#include <vector> 
#include <list> 
#include <forward_list> 
using namespace std;

int main(int argc, char const *argv[])
{
    list<string> a = {"sss","777","999"};
    auto it1 = a.begin();

    for(auto x = a.begin(); x!=a.end() ;x++)
    {
        cout<<*x<<" ";
    }
    cout<<endl; 

    for (auto p = a.begin(); p != a.end(); ++p) {  // a list of values
		std::cout << *p << "\n";
    }

    vector<string> svec;
    svec.insert(svec.begin(),"2323");

    cout << svec[0] << "\n";
    forward_list<int> flst = {1,3,4,5,6,6,7};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if(*curr % 2){
            curr = flst.erase_after(prev);

        }else{
            prev = curr;
            ++curr;
        }
        /* code */
    }
    

    return 0;
}


                      
