#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{


    string s1 = "1232g";
    string s2 = "123g";
    

    if (s1 == s2)
    {
        cout <<  "s1 = s2" << endl;
    }else{
         cout <<  "s1 != s2" << endl;
    }
    


string line;
while (getline(cin,line))
{
    cout << line << endl;
}


    return 0;
}
