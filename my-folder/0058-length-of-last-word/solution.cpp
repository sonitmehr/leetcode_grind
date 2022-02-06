#include <stack>
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool space = false;
        int n = s.size();
        
        for(int i = n-1;i>=0;i--){
            if(s[i] == ' ' && space == true){
                break;
            }if(isalpha(s[i])){
                space = true;
                count++;
            }
        }
        return count;
        
        
    }
};
