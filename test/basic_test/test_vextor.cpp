#include <iostream>
#include <vector>

using namespace std ;

int main(int argc, char const *argv[])
{
    // vector create and init 

    vector<int> first = {1,2,3};
    vector<string> to{"s","b"};
    vector<int>  s1(10,-1);
    vector<string> s3(10,"gggggg");

    for (auto i : s3)
    {
        cout << i << " " ;
    }
    cout << endl;
    
    vector<string> s4(3); //  init by default null string

s4.push_back("ssssbbbbbbbbbbbb");
s4.push_back("ssssbbbbbbbbbbbb3");
s4[0] = "5677";

cout << s4[3] <<  ",99999" << endl; 
  for (auto i : s4)
    {
        cout << i << " ---->>> " ;
    }
    cout << endl;

     return 0;
}
