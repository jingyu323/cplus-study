#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <iostream>
using std::cout; 

//读入并解析文件，将解析结果存入QueryResult对象中

class QueryResult;

class TextQuery
{

using _line_no = std::vector<std::string>::size_type;
public:
    //根据输入文件流将代查询文件按行存储到vector中并使用shared_ptr进行托管;建立每个单词和所在行数的对应关系，同样使用shared_ptr进行资源托管
        TextQuery(std::ifstream&);
        //根据单词和所在行的对应关系返回查询结果对象
        QueryResult query(const std::string&)const; 

 private:
//使用shred_ptr减少数据间进行复制次数，整个程序只有一份vector<string>存储查询文件;只有一份单词对应行数set<_lie_no>的存储
         //将每一行作为vector的一个元素进行存储
        std::shared_ptr<std::vector<std::string>>_file; 

        //存储每个单词和对应的行号
        std::map<std::string,
                std::shared_ptr<std::set<_line_no>>>_wm;
        static std::string cleanup_str(const std::string &);

};


#endif // TEXTQUERY_H