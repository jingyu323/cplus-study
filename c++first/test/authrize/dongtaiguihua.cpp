#include <vector>
#include <unordered_map>
using namespace std;

class dongtaiguihua
{
private:
    /* data */
public:
    dongtaiguihua();
    ~dongtaiguihua();
    // 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    int climbStairs(int n) {
         unordered_map<int, int> res;
         res[0]=0;
         res[1]=1;
         res[2]=2;
        if(n==1){  
            return 1;
        }
        if(n==2){  
            return 2;
        } 

        for(int i=3;i<=n;i++){
            int tmp_rs = res[i-1]+res[i-2];
            res[i]=tmp_rs;
        }

        return res[n];

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
      if( n<=1){
        return nums[0];
      }
      return  max(robhome(nums,0,n-2),robhome(nums,1,n-1));
    }
     
     int robhome(vector<int>& nums,int  start ,int end){
        int pre2 = 0, pre1 = 0;
        for (size_t i = start; i <= end; i++)
        {
             int cur =  max(pre1, pre2 + nums[i]);
             pre2 = pre1;
             pre1 = cur;
        }
        return pre1;
        

     }

 

int minPathSum(vector<vector<int>>& grid) {

                if (grid.size() == 0 || grid[0].size() == 0) {
                return 0;
            }
            int m = grid.size(), n = grid[0].size();
            vector<int> dp ;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        dp[j] = dp[j];        // 只能从上侧走到该位置
                    } else if (i == 0) {
                        dp[j] = dp[j - 1];    // 只能从左侧走到该位置
                    } else {
                        dp[j] = min(dp[j - 1], dp[j]);
                    }
                    dp[j] += grid[i][j];
                }
            }
            return dp[n - 1];
            
        }

  int uniquePaths(int m, int n) {
        // int dp[m][n]={0};

       
        vector<int> dp(n+1,1);

     

        for ( int i = 1; i < m; i++)
        {
            
            for (int j = 1; j < n; j++)
            {
                  
                 dp[j] = dp[j] + dp[j - 1];
            }
            
        }
         return dp [n - 1];
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() ==0){
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n+1);

        for (int i = 2; i < n; i++)
        {   // 递增子序列
             if (nums[i] - nums[i-1] ==nums[i-1] - nums[i-2] )
             {
                dp[i] = dp[i-1]+1;
             }
             
        }
        int total=0;
        for (int i = 0; i < dp.size(); i++)
        {
             total += dp[i];
        }
        return total;
        
        

    }

    int integerBreak(int n) {

        vector<int> dp(n+1);
        dp[1] = 1;
        for (int i = 1; i <= n; i++)
        {   
            for (int j = 1; j < i-1; j++)
            {
                dp[i] = max(dp[i],  max(j * dp[i - j], j * (i - j)));
            }
            
            
            
        }
        return dp[n];

    }


};

dongtaiguihua::dongtaiguihua(/* args */)
{
}

dongtaiguihua::~dongtaiguihua()
{
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

