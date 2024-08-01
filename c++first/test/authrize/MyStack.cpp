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

// 最小操作数
     int minOperations(vector<int>& nums, int x) {
         int sum = 0, n = nums.size(), len = INT_MIN;
         for (auto e : nums)
         {
             sum += e;
         }

         if (sum == x)
         {
             return n;
         }

         int target = sum -x ;
         if (target < 0)
         {
             return -1;
         }
         
         int v_sum = 0;

         for (int left = 0, right=0; right < n; right++)
         {
            v_sum += nums[right];

            while (left < n && v_sum >= target)
            {
                 if (v_sum == target)
                 {
                    len = max(len,right-left+1);
                 }
                 v_sum -= nums[left++];
                 
            }
            
         }

         return len == INT_MIN ? -1 : n - len;
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
        int sum = 0;
        int len = nums.size();
        int max_ans=0;
        for (int  left = 0,right=0; right <  len; right++)
        {
             
             int in  =  nums[right];
             sum += in;
             while (sum > k)
             {
                 int out = nums[left];
                 sum -= out;
             }
             if(sum == k){
                
                len = max(len,right-left+1);

             }
             

        }
        return len;
        
         
    }
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int len = nums.size();
        int max_ans=0;
        int total = 0;

        if(len == 1&& nums[0] != k){
            return 0;
        }

        for (int  left = 0,right=0; right <  len; right++)
        {
             
             int in  =  nums[right];
             sum += in;
             while (sum > k)
             {
                 int out = nums[left++];
                 sum -= out;
             }
             if(sum == k  ){
                max_ans++;
             }
        }
        return max_ans;
    } 
    int calculate(string s ){
         stack<int> ops;
         ops.push(1);
         int sign = 1;
         int  len = s.size();
         int n =0;
         long ret  =0 ;

         while (n< len)
         {  
            if ( s[n] == ' ')
            {
                n++;
            } 
             else if ( s[n] == '+')
            {
                 sign = ops.top();
                 n++;
            }
             else if ( s[n] == '-')
            {
                 sign = -ops.top();
                  n++;
            }
            else if ( s[n] == '(')
            {
                ops.push(sign);
                 n++;
            }
            else if ( s[n] == ')')
            {
                ops.pop();
                  n++;
            }else{
                long sum = 0;
              while (n < len &&    s[n] >= '0' &&  s[n] <= '9')
              {
                 sum = sum*10 +  s[n] - '0';

                cout << "=======sum : " <<  sum*10 +  s[n] - '0'<<  endl; 
                 n++;
              }
              ret += sum * sign;
              
            }   
         }
        return ret ;

    }
     int fib(int n) {
         if(n<=1){
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
    int tribonacci(int n) {

         if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        int p = 0, q = 0, r = 1, s = 1;
        for (int i = 3; i <= n; ++i) {
            p = q;
            q = r;
            r = s;
            s = p + q + r;
        }
        return s;  

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

         int prev = 0, curr = 0;

        for (int i=2;i<=n;i++){
         
            int next = min(curr + cost[i - 1],prev+cost[i - 2]);
            prev  =curr;
            curr = next;


        }
        return curr;

        

    }
    int rob(vector<int>& nums) {
      int n = nums.size();
      if( n<=1){
        return nums[0];

      }

        int prev = nums[0], curr = max(nums[0],nums[1]);

        for (int i=2;i<n;i++){
            int tmp = curr;
         
            int curr = max(prev + nums[i ],curr);
            prev  =tmp; 


        }
        return curr;
         
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(nums.size());

        for (auto s : nums)
        { 
             cnt[s]++;
        }
        vector<int> dp {cnt[0], max(cnt[0], cnt[1])};

         for (int i = 2; i < cnt.size(); i++) {
            dp.push_back(max(cnt[i] * i + dp[i - 2], dp[i - 1]));

         }

         return dp[nums.size()-1];
        

    }

    int uniquePaths(int m, int n) {
        // int dp[m][n]={0};

        vector<vector<int>> dp (m, vector<int>(n));


        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
           dp[0][j] = 1;
        }
 

        for ( int i = 1; i < m; i++)
        {
            
            for (int j = 1; j < n; j++)
            {
                  
                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            
        }
         return dp[m - 1][n - 1];
    }

        int minPathSum(vector<vector<int>>& grid) {

            int m =  grid.size();
            int n = grid[0].size();

             if (m == 0 || n == 0) return 0;

            vector<vector<int>> dp (m, vector<int>(n,0));

             dp[0][0] = grid[0][0];

            for (int i = 1; i < m; ++i) {
            dp[i][0] = grid[i][0] +dp[i-1][0];
            }
            for (int j = 1; j < n; ++j) {
            dp[0][j] = grid[0][j] +dp[0][j-1];
            }
            for ( int i = 1; i < m; i++)
            {
                
                for (int j = 1; j < n; j++)
                {
                    
                    dp[i][j] = min(dp[i - 1][j],dp[i][j - 1])  + grid[i][j] ;
                     cout << "=======sum : " << dp[i][j] <<  endl; 
                }
                
            }
            return dp[m - 1][n - 1];

        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            
             int m =  obstacleGrid.size();
            int n = obstacleGrid[0].size();

            vector<vector<int>> dp (m+1, vector<int>(n+1));
 
        bool vhasobs = false;
        for (int i = 0; i < m; ++i) {
            // cout << "=======sum : " << m <<  "  n: "<< n <<  endl; 
            if(obstacleGrid[i][0] == 0 && !vhasobs){
                 dp[i][0] = 1;
            }else{
                vhasobs= true;
                dp[i][0] = 0;
            }
           
        }
  
        bool hasobs = false;
        for (int j = 0; j < n; ++j) {
            
           if(obstacleGrid[0][j] == 0 && !hasobs){
            dp[0][j] = 1;
           }else{
                hasobs = true;
                dp[0][j] = 0;
                // cout << "=======sum 2: " << m <<  j <<dp[0][j] <<  endl; 
                 
           }
        }
        if(m<= 1){
            return dp[0][n-1];
        }
        for ( int i = 1; i < m; i++)
        {
            
            for (int j = 1; j < n; j++)
            {
                 if (obstacleGrid[i][j] == 0)
                 {
                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                 }else{
                     dp[i][j]=0;
                 }
                 
            }
            
        }
         return dp[m-1 ][n-1 ];
    }

    int minimumTotal(vector<vector<int>>& triangle) {

    }


    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());

        sort(s.begin(),s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size())
        {
                if(g[child] <= s[cookie]){
                    child ++;
                   
                }
                 cookie ++;
        }
        return child;
        


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

     cout << len << " "<< std::endl;;

    long ret =  S1.calculate("1 + 1");
     cout <<  "res: "<< ret  << std::endl;;

     
    return 0;
}