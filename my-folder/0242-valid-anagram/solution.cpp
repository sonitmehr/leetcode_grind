#include <iostream>
class Solution {
public:
    bool isAnagram(string s, string t) {
        int charmap[26];
        memset(charmap, 0, sizeof(charmap));
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0;i<s.size();i++){
            charmap[s.at(i) - 'a']++;
            charmap[t.at(i) - 'a']--;
        }
        for(auto i : charmap){
            if(i!=0){
                return false;
            }
        }
        return true;
        
    }
};
