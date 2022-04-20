#include <list>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    list<string> lst;
    auto iter = lst.begin();
     char word[50];
    while (cin >> word)
    {
        iter = lst.insert(iter,word);
    }
    
      for(auto x = lst.begin(); x!=lst.end() ;x++)
    {
        cout<<*x<<" ";
    }


    for (size_t i = 0; i < lst.size(); i++)
    {
         

        //  cout<<lst[i]<<" ";
    }
    

  // 不能用for 下标取值，还需要研究一下 输入之后怎么输出的问题
    

    return 0;
}
