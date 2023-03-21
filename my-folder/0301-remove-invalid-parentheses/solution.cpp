class Solution {
public:
    unordered_set<string> ans;
    
    void f(int i,int leftRemove,int rightRemove,int maxK,int pair,string s,string t){
        if(i > s.size())return;
        if(leftRemove + rightRemove > s.size() - i)return;
        if(i == s.size()){
            if(leftRemove == 0 && rightRemove == 0 && pair == 0){
                ans.insert(t);
            }
            return;
        }
        
        if(isalpha(s[i])){
           
            f(i + 1,leftRemove,rightRemove,maxK,pair,s,t + s[i]);
        }
        else{
            if(s[i] == '('){
                if(leftRemove > 0){
                    f(i + 1,leftRemove - 1,rightRemove,maxK,pair,s,t);
                }
                f(i + 1,leftRemove ,rightRemove,maxK,pair + 1,s,t + s[i]);
            }
            else{
                if(rightRemove > 0){
                    f(i + 1,leftRemove,rightRemove - 1,maxK,pair,s,t);
                }
                if(pair > 0)f(i + 1,leftRemove,rightRemove,maxK,pair - 1,s,t + s[i]);
            }
        }
        
        
    }   
   
    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        int rightRemove = 0;
        for(auto &i : s){
            if(i =='(')st.push(i);
            else if(i == ')'){
                if(st.size())st.pop();
                else rightRemove++;
            }
        }
        int leftRemove = st.size();
        
        string t;
        f(0,leftRemove,rightRemove,leftRemove + rightRemove,0,s,t);
        vector<string> anss(ans.begin(),ans.end());
        if(anss.size() == 0)return {""};
        return anss;

    }
};
