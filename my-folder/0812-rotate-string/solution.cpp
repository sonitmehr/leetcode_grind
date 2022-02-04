#include <iostream>
#include <string>
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i=0;i<n;i++){
            char str1 = s[0];
            s.erase(0,1);
            s.push_back(str1);
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};
