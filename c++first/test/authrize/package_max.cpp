// 贪心算法
// 定义一个结构体，用于存储物品的重量、价值和单位重量价值
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <iostream>

 



using namespace std; 

typedef struct item
{
    int weight; // 物品的重量
    int value; // 物品的价值
    double ratio; // 物品的单位重量价值
} item;


// 定义一个函数，用于比较两个物品的单位重量价值，用于排序
int compare(const void *a, const void *b)
{
    item *x = (item *)a;
    item *y = (item *)b;
    if (x->ratio > y->ratio) // 如果x的单位重量价值大于y的，返回-1，表示x排在y前面
    {
        return -1;
    }
    else if (x->ratio < y->ratio) // 如果x的单位重量价值小于y的，返回1，表示x排在y后面
    {
        return 1;
    }
    else // 如果x的单位重量价值等于y的，返回0，表示x和y的顺序不变
    {
        return 0;
    }
}



// 定义一个函数，用于求解背包问题，输入参数为物品的重量数组w，物品的价值数组v，物品的数量n，背包的容量C
int knapsack(int w[], int v[], int n, int C)
{
    // 定义一个数组，用于存储每种物品的信息
    item items[n];
    // 遍历每种物品，计算其单位重量价值，并存入数组中
    for (int i = 0; i < n; i++)
    {
        items[i].weight = w[i]; // 物品的重量
        items[i].value = v[i]; // 物品的价值
        items[i].ratio = (double)v[i] / w[i]; // 物品的单位重量价值
    }
    // 对数组按照单位重量价值进行降序排序
    qsort(items, n, sizeof(item), compare);
    // 定义一个变量，用于记录背包中物品的总重量，初始值为0
    int m = 0;
    // 定义一个变量，用于记录背包中物品的总价值，初始值为0
    int s = 0;
    // 从第一个物品开始，遍历每个物品，判断是否可以放入背包
    for (int i = 0; i < n; i++)
    {
        // 如果当前物品的重量加上背包中物品的总重量小于等于背包的容量，就放入背包
        if (items[i].weight + m <= C)
        {
            // 更新背包中物品的总重量
            m = m + items[i].weight;
            // 更新背包中物品的总价值
            s = s + items[i].value;
        }
        // 否则，跳过该物品，继续下一个物品
        else
        {
            continue;
        }
    }
    // 返回背包中物品的总价值，即为最优解
    return s;
}

vector<int> twoSum(vector<int>& numbers, int target) {
        
        int start=0,end= numbers.size()-1;
          vector<int> res(2);

        while (start < end)
        {
                int sum=numbers[start]+numbers[end];
                if(sum == target){
                    res[0]=start+1;
                    res[1]=end+1;
                    break;
                }else{

                    if (sum>target)
                    {
                        end--;
                         
                    }else{
                        start++;
                    }
                    
                }

             
        }

        return res;
        


}

string reverseVowels(string s) {
    unordered_map<char,int> yu={{'a',1},{'o',1},{'e',1},{'i',1},{'u',1},{'A',1},{'O',1},{'E',1},{'I',1},{'U',1}};
    int start = 0,end =s.size()-1;
    while (start< end)
    {
         char chs = s[start];
         char che = s[end];

         if (yu[chs] ==1 && yu[che] ==1)
         {
            s[start] = che;
            s[end] = chs;
            start++;
            end--;
         }else if (yu[chs] !=1)
         {
             start++;
         }else if (yu[che] !=1) {
            end--;
         }
         
         

    }

    return s;
    



}
 
    bool checkPalindrome(const string& s, int low, int high) {
            for (int i = low, j = high; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        } 
        bool validPalindrome(string s) {
            int dele = 0;
            int start = 0,end =s.size()-1;
            while (start< end)
            {
                if(s[start] == s[end]){
                    start++;
                    end--;
                }else{
                    return checkPalindrome(s,start,end-1) ||  checkPalindrome(s,start+1,end) ;
                    
                }
            }

        return true;
        }
 

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index1 = m-1;
    int index2= n-1;
    int megeindex=n+m-1;

    while ( index2 >= 0)
    {
        if(index1<0){
            nums1[megeindex--] = nums2[index2--];

        }else if (index2 <0 )
        {
           nums1[megeindex--] = nums1[index1--];
        }else if ( nums1[index1] >  nums2[index2] )
        {
            nums1[megeindex--] = nums1[index1--];
        }else{
            nums1[megeindex--] = nums2[index2--];
        }

    }
}
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

    bool hasCycle(ListNode *head) {

        if (head==NULL)
        {
             return false;
        }
        

        ListNode* cur= head ;
        ListNode*  nextnode=head->next;


       while (cur != NULL && nextnode  != NULL && nextnode->next != NULL) {
        if (cur == nextnode) {
            return true;
        }
        cur = cur->next;
        nextnode = nextnode->next->next;
    }
    return false;
    }

    bool isSub(string s,string  target ){
        int sl = s.size();
        int tl = target.size();

        int i=0,j=0;

        while ( i< sl && j < tl)
        {
             if(s[i] == target[j]){
                j++;
             }
             i++;
        }

        return j == tl;
    }

    // 524. Longest Word in Dictionary through Deleting (Medium)
    // Leetcode / 力扣
    string findLongestWord(string s, vector<string>& dictionary) {
        string  maxlongword= "";
        for (size_t i = 0; i < dictionary.size(); i++)
        {
             int mlength = maxlongword.size();
             int l2 = dictionary[i].size();

             if(mlength  > l2 || ( mlength == l2 && maxlongword <dictionary[i] )){
                continue;
             }
             if(isSub(s,dictionary[i])){
                maxlongword = dictionary[i];

             }

        }
        return maxlongword;
    }

// 主函数
int main()
{
    // 定义物品的重量数组
    int w[] = {10, 20, 30};
    // 定义物品的价值数组
    int v[] = {60, 100, 120};
    // 定义物品的数量
    int n = sizeof(w) / sizeof(w[0]);
    // 定义背包的容量
    int C = 50;
    // 调用函数，求解背包问题
    int result = knapsack(w, v, n, C);
    // 打印结果
    printf("The maximum value of the knapsack is %d\n", result);
    // 返回0，表示程序正常结束

    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";

    validPalindrome(s);


    return 0;
} 