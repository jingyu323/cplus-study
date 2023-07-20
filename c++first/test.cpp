
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 void test_while(){
    int a = 100;

    while (a >0)
    {
        /* code */
        a = a -10;

        cout << a << " ";
    }
    cout << endl;
    
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const   string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

  test_while();
    return 0;
}


