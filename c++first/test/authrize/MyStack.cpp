#include <iostream>
#include <queue>
#include <stack> 
#include <unordered_map>



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

    void verctorinit(){
         int n = 3;
  
    // Create a vector of size n with
    // all values as 10.
    vector<int> vect(n, 10);
  
    for (int x : vect)
        cout << x << " "; 
    }
    
    void verctorinitasarr(){
        vector<int> vect{ 10, 20, 30 };
  
    for (int x : vect)
        cout << x << " "; 
    }
    void verctorinitasarr2(){
        int arr[] = { 10, 20, 30 };
        int n = sizeof(arr) / sizeof(arr[0]);

        vector<int> vect(arr,arr+n);
  
    for (int x : vect)
        cout << x << " -- "; 
    }
    
    void verctorinitasarr3(){   
       vector<int> vect1{ 10, 20, 30 };

        vector<int> vect2(vect1.begin(),vect1.end());
  
        for (int x : vect2)
            cout << x << " -. "; 
    }

// 无重复字符最长子串
    int lengthOfLongestSubstring(string s) 
    {
        int len = 0, n = s.size();
        unordered_map<char, int> hash;

        for (int left = 0, right = 0; right < n; right++)
        {   
            char in = s[right];
            hash[in]++;

            while (hash[in] > 1)
            {
                 char out = s[left++];
                 hash[out]--;
            }

            len = max(len ,right-left+1);
        }

        return len;
    }
    // 最大连续1的个数
     int findMaxConsecutiveOnes(vector<int>& nums){
        int len = 0, n = nums.size();
        for (int left = 0, right = 0; right < n; right++)
        {   
            if( nums[right]==1){
                len = max(len,right -left+1) ;

            } else{
                left =right+1;
            }

        }

        return len;


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
            tmp_que.push(data.front());
            data.pop();
         }

         while (!tmp_que.empty())
         {
            data.push(tmp_que.front());
            tmp_que.pop();
         }
}


int main(int argc, char const *argv[])
{
 
     MyStack S1;
     S1.push(1);
     S1.push(2);
     S1.push(3);

     while (!S1.isEmpty())
     {  
        int a = S1.pop();
         cout << a  << endl;
     }



    vector<int> vect;
    
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
 
    for (int x : vect)
        cout << x << " ";


    S1.verctorinit();
    S1.verctorinitasarr();
    S1.verctorinitasarr3();
    S1.verctorinitasarr2();

    string s = "bbb";

    int len = S1.lengthOfLongestSubstring(s);

     cout << len << " ";
 

     
    return 0;
}