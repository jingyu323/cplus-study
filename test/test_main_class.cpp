#include <iostream> 
#include "Sales_data.cpp" 
// vscode 中要使用实现类需要引用cpp文件


using namespace std;

int main(int argc, char const *argv[])
{
    
    Sales_data data = Sales_data("asa");
     bool res =   data.same_isbn("777");
     cout << "res:"<<res<< endl;
    return 0;
}


