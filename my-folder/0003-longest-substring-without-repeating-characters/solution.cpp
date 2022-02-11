#include <iostream>
#include <string>
#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0,r=0,maxInt = 0;
        if(n == 0)return 0;
        unordered_set<char> set;
        while(r<n){
            if(set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            else{
                set.insert(s[r]);
                int size_set = set.size();
                maxInt = max(size_set,maxInt);
                r++;
            }
           
        }
        return maxInt;
    }
};
