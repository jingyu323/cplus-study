
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
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &str) { data->push_back(str); }
	    void pop_back();
	    string& front() { return do_front(); }
	    const string& front() const { return do_front(); }  //基于const的重载
	    string& back() { return do_back(); }
	    const string& back() const { return do_back(); } 
        
    private:
        shared_ptr<vector<string>> data;
        string& do_front() const {    //类内定义，所以隐式内联函数，不会有额外的运行时开销
		check(0, "front on empty StrBlob");
		return data->front();
	    }
        string& do_back() const {
            check(0, "back on empty StrBlob");
            return data->back();
        }
        void check(size_type i, const string &msg) const; 


};


StrBlob::StrBlob() :data(make_shared<vector<string>>()) {};

StrBlob::StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {};

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw runtime_error(msg);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


int main(int argc, char const *argv[])
{
    /* code */

    
    const StrBlob p({ "a","an" });
    // p.push_back("888");
cout<< p.size()<< endl; 
    // p.push_back("the");
    // 定义为常量的strblob 就不应该被修改所以实现push_back咩有意义
    return 0;
}
