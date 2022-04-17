#include <iostream>
using namespace std;

class  Sales_data
{
friend Sales_data add(const Sales_data&,const Sales_data&);
public:
     Sales_data(string isbn);
    
    bool same_isbn(string isbn);

private:
    string isbn;
    unsigned units_sold = 0;
    double renvenus = 0.0;
};
