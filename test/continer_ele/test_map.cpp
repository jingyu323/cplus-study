#include <iostream>
#include <map>

using namespace std;


/**
 * 关联容器
 * map
 * 
 */



int main(int argc, char const *argv[])
{
    
    map<string , size_t> word_count;
string word;

// while (cin >> word)
// {
//     ++word_count[word];
// }

// for (const auto &w :word_count)
// {
//     cout << w.first << " occurs " << w.second << ( (w.second >1 )  ? "times" :"time") << endl;
// }

std::map < int , std::string > mapPerson;
mapPerson.insert(pair < int,string > (1,"Jim"));
mapPerson.insert(std::map < int, std::string > ::value_type (2, "Tom"));

mapPerson[3] = "jerry";

std::map < int ,std::string > ::iterator it;
    std::map < int ,std::string > ::iterator itEnd;
    it = mapPerson.begin();
    itEnd = mapPerson.end();
    while (it != itEnd) 
    {
		cout<<it->first<<' '<<it->second<<endl;  
		it++;
	}

map<int,string > ::iterator l_it;;
   l_it = mapPerson.find(1);
   if(l_it != mapPerson.end()){
                cout<<"we do not find 112"<<endl;

                 std::cout<<"Find, the value is "<<l_it->second<<endl;
   }
             
   else cout<<"wo find 112"<<endl; 

   auto ret = mapPerson.insert({4,"ttt4"});

   cout<<ret.second<<endl;

   
   auto ret2 = mapPerson.insert({4,"ttt4"});

   cout<< "ret:"<<ret2.second<<endl;

      cout<<ret2.first->first <<endl;
      cout<<ret2.first->second <<endl;

   // 如果元素不存在 返回值成功1也就是true，如果元素已经存在，则返回值为0 也就是false



    return 0;
}
