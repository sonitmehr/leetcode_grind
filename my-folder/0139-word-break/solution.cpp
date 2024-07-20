class Solution {
public:

    bool solve(int i,unordered_set<string> &st,string &s,vector<int> &dp){
        if(i == s.size()){
            return true;
        }

        if(dp[i] != -1)return dp[i];
        string t;
        for(int ind = i;ind<s.size();ind++){
            t.push_back(s[ind]);
            if(st.find(t) != st.end()){
                // cout << t << endl;
                if(solve(ind + 1,st,s,dp))return dp[i]=true;
            }
        }
        return dp[i]=false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        return solve(0,st,s,dp);
    }
};
