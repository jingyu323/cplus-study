size_t还经常出现在C++标准库中，此外，C++库中经常会使用一个相似的类型size_type，用的可能比size_t还要多。

size_t类型是一个类型定义，通常将一些无符号的整形定义为size_t，比如说unsigned int或者unsigned long，甚至unsigned long long。每一个标准C实现应该选择足够大的无符号整形来代表该平台上最大可能出现的对象大小。
———————————————— 

可以理解为就是一个类型定义为了跨平台而生的
