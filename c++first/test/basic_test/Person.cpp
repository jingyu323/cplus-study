#include <iostream>

class Person
{
private:
    /* data */
    char _name[20];
    char _gender[3];
    int _age;
public:
    Person(  char   &name ,char gen[3]);
    ~Person();
    void PrintPersonInfo();
};

Person::Person( char   &name ,char gen[3] )
{
        _name =name;
        _gender[3]  = gen[3];
}

Person::~Person()
{

    std::cout<<"Destructorcalled"<<_age<<std::endl;
}

void Person::PrintPersonInfo()
{
    
    std::cout << _name << " dddd  " << _gender << " " << _age << std::endl;
}

int main(int argc, char const *argv[])
{
    
// 类的实例化

    char gen[3] = {'f','m'};
     char name[20] ={'f','m','m','m','m','m','m','m22'};
     Person* myObject = new Person(name,gen);
     
 

     myObject->PrintPersonInfo();

    return 0;
}

