#include "QueryResult.h"
#include "TextQuery.h"
#include "TextQuery.cpp"

#include "make_pluarl.h"
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
    string filename ="test.txt";
    std::ifstream inputfile(filename);
    TextQuery text(inputfile);
    while(true){
        cout << "Enter word to look for, or q to quit: ";
        string sought;
        if(!(std::cin >> sought)||sought=="q")
            break;
        cout << text.query(sought) << endl;
    }
    return 0;
} 