#include <iostream>
using namespace std;

class  Sales_data
{
private:
    string isbn;
    unsigned units_sold = 0;
    double renvenus = 0.0;
public:
     Sales_data(string isbn);
    
    bool same_isbn(string isbn);
};
