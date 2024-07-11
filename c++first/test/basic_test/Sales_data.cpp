#include <istream>
#include <string>
 
#include <iostream>

class Sales_data{
    
   public:
	void information()
	{
		 std::cout << _name << "-" << _age << std::endl;
	}
    public:
	char* _name;
	int _age;

};


int main()
{   

    Sales_data *sd1,sd;
    sd1 = new Sales_data;
    sd1 = &sd;
    sd._age = 3;
    sd._name="cccc";

    // sd1->information();

    sd.information();


    delete sd1; 
	

    return 0;
}

