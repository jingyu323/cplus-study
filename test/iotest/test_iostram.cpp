#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    auto old_status = cin.rdstate();
    cin.clear();

    process_input(cin);

    cin.setstate(old_status);
     
    return 0;
}


/**
 * 流的状态
 * badbit 发生从错误无法恢复
 * failbit  发生错误还可以修复
 * eofbit 
 * gootbit  值为0 
 */