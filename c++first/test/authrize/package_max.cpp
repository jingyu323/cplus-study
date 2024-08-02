// 贪心算法
// 定义一个结构体，用于存储物品的重量、价值和单位重量价值
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

 



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

    unordered_map<string, int> hash1;

     int a =1;
     int b=2;


    return 0;
} 