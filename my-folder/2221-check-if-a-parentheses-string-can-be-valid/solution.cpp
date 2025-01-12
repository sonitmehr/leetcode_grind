class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        int open = 0;
if(n%2 == 1)return false;
        for(int i = 0;i<n;i++){
            if(locked[i] == '0' || s[i] == '(')open++;
            else open--;
            if(open < 0)return false;
        }
        open = 0;
        for(int i = n - 1;i>=0 ;i--){
            if(locked[i] == '0' || s[i] == ')')open++;
            else open--;
            if(open < 0)return false;
        }
        
        return true;
    }
};
