#include <iostream>
using namespace std;
#include <set>

void print(set<int> &s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


void test01()
{
    set<int> s;
    s.insert(20);
    s.insert(40);
    s.insert(1);
  auto ret=  s.insert(2);

if(ret.second){
        cout<<"³É¹¦,pair value is:" << *ret.first << ","  << ret.second <<endl;
    }else{
        cout<<"faild"<<endl;
    }
    print(s);
    //1 2 20 40
}

int main()
{
    test01();
    system("pause");
    return 0;

} 