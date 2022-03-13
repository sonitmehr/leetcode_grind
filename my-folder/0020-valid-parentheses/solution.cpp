class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        unordered_map<char,char> m = {{'(', ')'},{'{', '}'},{'[',']'}};
        stack<char> stack;
        stack.push(s[0]);
        for(int i = 1;i<n;i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            else if(m[stack.top()] == s[i]){
                stack.pop();
            }else stack.push(s[i]);
        }
        if(stack.empty())return true;
        return false;
        
        
        
    }
};
