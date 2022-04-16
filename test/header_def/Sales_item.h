#include <iostream>

#include <string>

using namespace std;

class Sales_item
{
private:
     string isbn;
     unsigned unit_sold;
     double revenue;
public:
    Sales_item(/* args */);
    ~Sales_item();
    double avg() const;
    bool same_isbn(const Sales_item &rhbs) const{
        return isbn == rhbs.isbn;

    }
};

Sales_item::Sales_item(/* args */)
{
}

Sales_item::~Sales_item()
{
}
