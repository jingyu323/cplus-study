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

  
    

    return 0;
}
