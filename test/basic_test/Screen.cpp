#include <iostream>
using namespace std;


class Screen
{

 
 friend class Window_mgr;

 public:
    typedef string::size_type pos;

private:
pos cursor = 0;
pos height = 0,width= 0;
string contents;
};

