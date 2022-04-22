#ifndef MAKE_PLUARL_H_INCLUDED
#define MAKE_PLUARL_H_INCLUDED
#include <string>
//判断行数是不是复数
inline
std::string make_pluarl(size_t ctr, std::string word,std::string ending ){
    return (ctr==1)? word : word+ ending;
}


#endif 