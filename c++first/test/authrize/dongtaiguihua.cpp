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

