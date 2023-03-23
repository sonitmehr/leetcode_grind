class Solution {
public:
    int dp[1001];
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        memset(dp,0,sizeof(dp));
        
        int n = s.size();
        dp[n] = 1;
        for(int i = n - 1;i>=0;i--){
            for(auto &word : wordDict){
                if(i + word.size() <= n && s.substr(i,word.size()) == word){
                    //cout << s.substr(i,word.size()) << " " << word << endl;
                    dp[i] = dp[i + word.size()];
                }
                if(dp[i] == 1)break;
            }
        }
        return dp[0];
        

    }
};
