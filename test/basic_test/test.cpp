#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum(int a , int b)
{

  return a + b;

}
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    int a = 1;
    int b = 2;
    int dd = sum(a,b);
    cout << dd;
    cout << endl;

}

