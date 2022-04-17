#include <iostream>
#include "Sales_data.h" 
using namespace std;

Sales_data::Sales_data(string isbn){
    
    cout << "执行构造函数了" << endl;
    this->isbn = isbn;
    

}

bool Sales_data::same_isbn(string isbn){

    cout<< isbn<< ",,,tttt   " << Sales_data::isbn << endl;
 return  Sales_data::isbn == isbn;

}