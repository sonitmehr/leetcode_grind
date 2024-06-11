class Solution {
public:

    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){

        // if(i < 0 && j < 0)return 1;
        if(j < 0)return 1;
        if(i < 0)return 0;

        if( dp[i][j] != - 1)return dp[i][j];    
        int one = 0,two = 0;
        if(s[i] == t[j]){
            one += (solve(i - 1,j - 1,s,t,dp) + solve(i -1,j,s,t,dp));
        }
        else{
            two += solve(i - 1,j,s,t,dp);
        }
        return dp[i][j] = one + two;
    }

    int numDistinct(string s, string t) {
        int n = s.size(),m =t.size();
        vector<vector<int>> dp(n + 1,vector<int> (m + 1,0));
        cout << s.size() << endl;
        for(int i= 0;i<=n;i++)dp[i][0] = 1;
        int M = 1e9 + 7;
        for(int i = 1;i<=n;i++){
            for(int j= 1;j<=m;j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] =( dp[i - 1][j - 1] + dp[i - 1][j]) % M;
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
