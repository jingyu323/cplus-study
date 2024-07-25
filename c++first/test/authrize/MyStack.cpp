#include <iostream>
#include <queue>
#include <stack>
using namespace std; 
class MyStack
{
public:
    queue<int> data;
    /* data */
public:
    MyStack(/* args */);
    ~MyStack();

    void push(int x);
    
    int pop(){
        int x = data.front();
        data.pop();
        return x;
    }
    int top(){
        return data.front();
    }
    bool isEmpty(){
        return data.empty();
    }
};

MyStack::MyStack(/* args */)
{
}

MyStack::~MyStack()
{
}

void MyStack::push(int x){
       std::queue<int> tmp_que;
         tmp_que.push(x);
         while (!data.empty())
         {
            tmp_que.push(tmp_que.front());

            data.pop();
         }

}


int main(int argc, char const *argv[])
{
    /* code */
     std::queue<int> tmp_que;
     stack<int> S1;
     
     S1.push(12);
     
     int a = S1.pop();
 

     cout<< " head3: "<< a <<endl;

    


    return 0;
}