class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> stack;
        int count = 0;
        for(auto i : s){
            if(i=='('){
                stack.push(count);
                count = 0;
            }else{
                count = stack.top() + max(2*count,1);
                stack.pop();
            }
                
        }
        return count;
    }
};
