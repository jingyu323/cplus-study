#include <iostream>
#include <exception>

using namespace std;

int main(int argc, char const *argv[])
{

    try
    {
         int a  = 34 /0; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

   

    /* code */
    return 0;
}

/**
 * @brief 
 * standrd exception lib
 * 1.runtime_error
 * 2.range_error
 * 3.excetion common error
 * 4.overflow_error :runtime error compute overflow
 * 5.logic_error : programe logic error
 * 6.invalid_argument: invalid arg
 * 
 */