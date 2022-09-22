class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int ans = 0;
        int open =0,close =0;
        for(int i= 0;i<n;i++){
            char c = s[i];
            
            if(s[i]=='(')open++;
            else close ++;
            
            if(close > open){
                close = 0;
                open = 0;
            }
            else if(close == open){
                ans = max(close + open,ans);
            }            
        }open =0,close=0;
        for(int i=n-1;i>=0;i--){
            char c = s[i];
            
            if(s[i]=='(')open++;
            else close ++;
            
            if(close < open){
                close = 0;
                open = 0;
            }
            else if(close == open){
                ans = max(close + open,ans);
            }            
        }
        return ans;
    }
};
