
#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace std;

class StrBlob {
    public:
        using size_type = vector<string>::size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        
    private:
        shared_ptr<vector<string>> data;


};