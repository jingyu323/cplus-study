#include <iostream>
#include <fstream> 

 
#include <sstream>
#include <string>

#include <vector> 

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};


int main(int argc, char const *argv[])
{
    /* code */

    string line,word;
    vector <PersonInfo> people;
    while (getline(cin,line))
    {
        /* code */

        PersonInfo info;

        istringstream record(line); // 将记录绑定到刚读入的行
        record>>info.name; //读取名字
    
        while (record >> word)
        {
        info.phones.push_back(word);
        
        }

        people.push_back(info);

    }
    for (size_t i = 0; i < people.size(); i++)
    {
        /* code */
        cout<< people[i].name << end;
        cout << "请输入姓名: [ctrl+z退出] ";
    }
    




    return 0;
}
