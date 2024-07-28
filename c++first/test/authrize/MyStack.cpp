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
    //   摘水果， 核心点在于 滑动窗口 控制采摘的种类， 巧妙运用 map中元素的自加加 自减减 调节map中的种类
     int totalFruit(vector<int>& fruits){

        int len =  fruits.size();
        unordered_map<int, int> hash;

        int num = 0;

        for (int left = 0,right = 0; right < len; right++)
        {
            int  fr = fruits[right];
            hash[fr]++;

            while (hash.size() > 2)
            {
                 int lr = fruits[left++];
                 hash[lr]--;
                 if (hash[lr] == 0) hash.erase(lr);
            }
            
            num = max(num ,right-left+1);
        }
        return num;
     }
     vector<int> findAnagrams(string s, string p) 
    {
        int count = 0;
        vector<int> ret;
        int hash1[26] = {0};
        for (auto ch : p) hash1[ch-'a']++;

        int hash2[26] = {0};
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (hash2[in-'a'] < hash1[in-'a']) count++;

            hash2[in-'a']++;

            if(right - left+1 > p.size()){
                int out = s[left++];
                if ( hash2[out -'a' ] <= hash1[out -'a' ]) 
                {
                   count--;
                }
                 hash2[out-'a']--;
            
            }
            if (count == p.size())
                ret.push_back(left);


        }

        return ret;
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int len = words.size() * words[0].size();
        unordered_map<string, int> hash1;
        for (auto& s : words) hash1[s]++;
        int n = s.size();
        vector<int> ret;

        for (int i = 0; i < words[0].size(); i++)
        {
            unordered_map<string, int> hash2;
            int count = 0;
            for (int left = i, right = i; right < n; right += words[0].size()){
                string in = s.substr(right, words[0].size());
                if(hash1.count(in) && hash2[in] <   hash1[in]  ){
                    count++;
                }
                hash2[in]++;

                if (right - left + 1 > len)
                {
                     string out = s.substr(left, words[0].size());
                     if(hash2[out] <= hash1[out]){
                        count--;
                     }
                     hash2[out]--;
                     left += words[0].size();
                }
                if (count == words.size()) ret.push_back(left);

            }
        }
         return ret;

    }

     string minWindow(string s, string t){
        if (s.size() < t.size()) return "";
        int kind = 0;
        int hash1[126] = {0};
        for (auto ch : t) if (hash1[ch]++ == 0) kind++;
        int hash2[126] = {0};
        int len = INT_MAX, begin = -1;  
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash2[in] == hash1[in]) count++;

            while (count == kind)
            {
                     if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }
                char out = s[left++];
                if (hash2[out] == hash1[out]) count--;
                hash2[out]--;

            }
            
        }
        if (begin == -1) return "";
        else return s.substr(begin, len);

     }

     int maxSubArrayLen(vector<int> &nums, int k) {
         
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