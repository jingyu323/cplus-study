#include "TextQuery.h"
#include "QueryResult.h"
#include "make_pluarl.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream> 
using std::string;
using std::vector;
using std::set;
using std::shared_ptr;
using std::endl;

TextQuery::TextQuery(std::ifstream& file)
:_file(new std::vector<std::string>()){

     std::string line_text;
    int line_no;
     std::string word;
      while(std::getline(file,line_text)){

            _file->push_back(line_text);
            line_no = _file->size()-1;

            std::istringstream line(line_text);//初始化
            while(line>>word){
                 word = cleanup_str(word);
                  auto& no = _wm[word];
                if(!no)
                    no.reset(new std::set<_line_no>);
                     no->insert(line_no);



            }

      }
}

QueryResult TextQuery::query(const std::string& sought)const{
    static shared_ptr<set<_line_no>> nodata(new set<_line_no>);
    auto it = _wm.find(cleanup_str(sought));
    if(it==_wm.end()){
        //查找的单词不存在
        return QueryResult(sought,_file,nodata);
    }else{
        //找到查找单词
        return QueryResult(sought,_file,it->second);
    }

} 

std::string TextQuery::cleanup_str(const std::string& word){

    string ret;

    for(auto it = word.begin();it!=word.end();++it){
        if(!ispunct(*it))
            ret += tolower(*it);
    }

    return ret; 
}

/**
 * @brief 重载运算符相当于Java的重载方法
 * 
 * @param os 
 * @param qr 
 * @return std::ostream& 
 */

std::ostream& operator << (std::ostream& os,const QueryResult& qr){
    os<<qr._sought<<" occur "<<qr._lines->size()<<" "
    <<make_pluarl(qr._lines->size(),"line","s")<<"\n";
    for(auto num : *qr._lines){
        os<<"\t(line: "<<num+1<<"): "
          <<*(qr._file->begin()+num)<<endl;
    }


    return os;
} 