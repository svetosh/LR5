#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void print(int a)
{
    cout << a << " ";
}
void printMap(pair<int, string> map) {
    cout << map.first << " " << map.second << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    unordered_multimap <int, string> multmap =
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
    multmap.insert({ { 4, "CBA" }, { 4, "CAB" } });
    for_each(multmap.begin(), multmap.end(), printMap);
    cout << endl;
    multmap.erase(4);
    for_each(multmap.begin(), multmap.end(), printMap);
    cout << endl;
    map<int, string> smap;
    for (auto& i : multmap)
    {
        smap[i.first] = i.second;
    }
    for_each(smap.begin(), smap.end(), printMap);
    //
    cout << "Колличество элементов с ключём от 0 до 6: " << count_if(smap.begin(),  
    smap.end(), [](auto& i) { return (i.first > 0) && (i.first < 6); });
    cout << endl;
    vector<int> key(smap.size());
    transform(smap.begin(),
              smap.end(),
              key.begin(),
              [](pair<const int, string > i)
              {
                return i.first;
              });
    for_each(key.begin(), key.end(), print); // vivod vector
    cout << endl;
    const int nine = 9;  // zada4a 3
    auto it = find(key.begin(), key.end(), nine);
    auto index = distance(key.begin(), it);
    replace(key.begin(), key.end(), 0, 3);  // replacing zero elements with 3
    for_each(key.begin(), key.end(), print);
    cout << endl;
    sort(key.begin(), key.end(), greater<int>()); // Sort descending
    for_each(key.begin(), key.end(), print);
    cout << endl;
    set<int> set;
    for (auto i : key) {
        set.insert(i);
    }
    for_each(set.begin(), set.end(), print);
    return 0;
}
