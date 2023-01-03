
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com
// 模版代码提供基本的输入输出框架，可按个人代码习惯修改



#include <iostream>
#include <string>
#include <vector>

int solution(int n, int pages[7],int length){
    int result;
    // TODO:
            while(n>0){
 
            printf("%d", length);//i=9
            for(int i=0;i< length ;i++){
                result = i+1;
                n = n - pages[i];
                if(n<=0){
                    break;
                }
            }
            
        }
    return result;
}

int main() {

    int n;
    int pages[7];

    std::cin>>n;
    
    for (int i = 0; i < 7; i++){
        std::cin>>pages[i];
    }
    

    int length=sizeof(pages)/sizeof(pages[0]);

    int result = solution(n, pages,length);

    std::cout<<result<<std::endl;

    return 0;
}