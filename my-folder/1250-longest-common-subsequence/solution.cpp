class Solution {
public:

    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i < 0 || j < 0)return 0;

        if(i == 0 && j == 0){
            return s1[i] == s2[j];
        }
        if(dp[i][j] != -1)return dp[i][j];
        int one = 0;

        if(s1[i] == s2[j]){
            one = 1 + solve(i - 1,j - 1,s1,s2,dp);
        }
        int two = solve(i-1,j,s1,s2,dp);
        int three = solve(i,j - 1,s1,s2,dp);

        return dp[i][j] = max({one ,two,three});
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();
        vector<vector<int>> dp(n1 + 1,vector<int> (n2 + 1));

        for(int i = 0;i<n1;i++)dp[i][0] = 0;
        for(int i = 0;i<n2;i++)dp[0][i] = 0;

            for(int i= 1;i<=n1;i++){
                for(int j = 1;j<=n2;j++){
                    int one = 0;
                    if(s1[i - 1] == s2[j - 1]) one =  1  + dp[i - 1][j - 1];
                    int two = max(dp[i - 1][j],dp[i][j - 1]);

                    dp[i][j] = max(one,two);
                }

            }

            return dp[n1][n2];
            
        }
    };
