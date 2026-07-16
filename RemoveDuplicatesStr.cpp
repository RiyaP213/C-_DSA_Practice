#include<iostream>
using namespace std;
// remove duplicates from a string using recursion

void RemoveDuplicates(string str, string ans, int i, bool map[]) {

    if(i == str.size()){
        cout << ans;
        return;
    }

    int mapIdx = str[i] - 'a';

    if(map[mapIdx]){
        RemoveDuplicates(str, ans, i+1, map);
    }
    else{
        map[mapIdx] = true;
        RemoveDuplicates(str, ans + str[i], i+1, map);
    }
}