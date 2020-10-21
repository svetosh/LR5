#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

void print_Key(const vector<int>& key)
{
    for (int i : key)
    {
        cout << i << ", ";
    }
    cout << endl;
}

int main()
{
    unordered_multimap < int, std::string> multmap = 
    {
         { 0 , "asd" },
         { 1 , "asdf" },
         { 2 , "asfgE" },
         { -2 , "FDsfsdaf" },
         { -8 , "ASFad" },
         { -7 , "SAdE" },
         { 12 , "AasdDE" },
         { 22 , "ABasdfE" },
         { 2 , "sadfDE" },
         { 4 , "sadfdsafDE" },
         { 3 , "gdfDEF" }
    };
    multmap.insert({ 4, "CBA" });
    multmap.insert({ 4, "CAB" });
    multmap.erase(multmap.find(4));
    map<int, string> smap;

        for (auto& i : multmap)
    {
        smap[i.first] = i.second;
        std::cout << i.first << " " << i.second << endl;
    }
        std::cout << endl;
        //////////////////////
        std::cout << "Koli4estvo elementov s key ot 0 do 6 = " << count_if(smap.begin(),
                                                                           smap.end(), [](auto& i) { return i.first > 0;
                                                                                                     return i.first < 6;
                                                                                                   });
        std::cout << endl;
        vector<int> key(smap.size());
        transform(smap.begin(),
            smap.end(),
            key.begin(),
            [](pair<const int, string > i)
            {
                return i.first;
            });
        print_Key(key);
}