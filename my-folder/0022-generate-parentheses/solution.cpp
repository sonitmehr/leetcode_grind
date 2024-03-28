class Solution {
public:

    void solve(int first,int last,vector<string> &ans,string s){
        
        if(first == 0 && last == 0){
           ans.push_back(s);
           return; 
        }
        if(first  < 0 || last < 0 || first > last)return;


        s.push_back('(');
        solve(first - 1,last,ans,s);
        s.pop_back();
        s.push_back(')');
        solve(first,last-1,ans,s);


    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(n,n,ans,s);
        return ans;
    }
};
