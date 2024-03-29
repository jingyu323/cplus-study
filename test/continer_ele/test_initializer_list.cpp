/**
 * @file test_initializer_list.cpp
 * @author your name (you@domain.com)
 * @brief  模板方法初始化模板
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<initializer_list>
#include<iostream>
using namespace std;
double sum(initializer_list<double> il);
double average(const initializer_list<double> &ril); 

int main(int argc, char const *argv[])
{
    /* code */

 cout << "sum:" << sum({2,3,4})
        << ", ave:" << average({2.0,3,4}) << endl;


         initializer_list<double> dl={1.5,2.5,3.5,4.5,5.5};
    cout << "sum:" << sum(dl)
        << ", ave:" << average(dl) << endl;

        dl={1,2,3,4,5,6};
    cout << "sum:" << sum(dl)
        << ", ave:" << average(dl) << endl;
    return 0;
}

double sum(initializer_list<double> il)
{
    double sum=0;
    for(auto tmp : il) sum+=tmp;
    return sum;
}

double average(const initializer_list<double> &ril)
{
    if(ril.size()>0)
    {
        double sum=0;
        for(auto tmp : ril) sum+=tmp;
        return sum/ril.size();
    }
    return 0.0;
} 
