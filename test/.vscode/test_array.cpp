#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
 
int main ()
{
   int n[ 10 ]; // n 是一个包含 10 个整数的数组
 
    for ( int i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; // 设置元素 i 为 i + 100
   }
   cout  << "Element" << setw( 13 ) << "Value" << endl;
 
   // 输出数组中每个元素的值                     
   for ( int j = 0; j < 10; j++ )
   
   {
      std::cout  << setw( 7 )<< j << setw( 13 ) << n[ j ] << std::endl;
   }
 int i; double d;
 d=i=3.5;
 cout<< d <<"  "<< i<< endl;

 i=d=3.5;
  cout<< d <<"  "<< i<< endl;

  cout << sizeof(d) << "  "<< sizeof(i) << endl;
   return 0;
}