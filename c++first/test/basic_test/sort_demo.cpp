#include <vector>
#include <c++/v1/list>
#include <iostream>  
#include <algorithm>


bool mycomp(int i, int j) {
    return (i < j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};


class mycomp3 {
public:
    bool operator() (int i, int j) {
        return (i > j);
    }
};

void sort_table(){
     printf("\n=================== sort_table   ==============\n");
    std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    //调用第一种语法格式，对 32、71、12、45 进行排序
    std::stable_sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    printf("\n=================== vector  td::greater  ==============\n");
    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::stable_sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); //(71 45 32 12) 26 80 53 33
    //调用第二种语法格式，通过自定义比较规则进行排序,这里也可以换成 mycomp2()
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    printf("\n=================== vector  td::mycomp  ==============\n");
    std::stable_sort(myvector.begin(), myvector.end(), mycomp);//12 26 32 33 45 53 71 80
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }

}

void partial_sort_demo(){
     printf("\n=================== partial_sort_demo  ==============\n");
    std::vector<int> myvector{ 3,2,5,4,1,6,9,7};
    //以默认的升序排序作为排序规则，将 myvector 中最小的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end());
    std::cout << "第一次排序:\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
    std::cout << "\n第二次排序:\n";
    // 以指定的 mycomp2 作为排序规则，将 myvector 中最大的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 3, myvector.end(), mycomp3());
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
}

int main(int argc, char const *argv[])
{
    
 std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    //调用第一种语法格式，对 32、71、12、45 进行排序
    std::sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33
 //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }

    printf("\n=================== vector  td::greater  ==============\n");

    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); //(71 45 32 12) 26 80 53 33
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }


    printf("\n=================== vector  td::less  ==============\n");

    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::sort(myvector.begin(), myvector.begin() + 6, std::less<int>()); //(71 45 32 12) 26 80 53 33
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }

    printf("\n=================== vector    ==============\n");
    //调用第二种语法格式，通过自定义比较规则进行排序
    std::sort(myvector.begin(), myvector.end(), mycomp2());//12 26 32 33 45 53 71 80
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
 printf("\n=================== is_sorted    ==============\n");
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (is_sorted(myvector.begin(), myvector.end())) {
        std::cout << "开始对 myvector 排序" << std::endl;
        //......
    }

    // sort_table();
    partial_sort_demo();


    return 0;
}
