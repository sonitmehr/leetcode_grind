class Solution {
public:
    string s1,s2;
    int n1,n2;
    int f(int i,int j,vector<vector<int>> &dp){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j])return 1 + f(i - 1,j - 1,dp);

        return dp[i][j] = max(f(i - 1,j,dp),f(i,j-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        n1 = s1.size();
        n2 = s2.size();
        vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,-1));
        return f(n1-1,n2-1,dp);
        // for(int i = 0;i<n1;i++)dp[i][0] = 0;
        // for(int i = 0;i<n2;i++)dp[0][i] = 0;

        // for(int i = 1;i<=n1;i++){
        //     for(int j = 1;j<=n2;j++){
        //         if(s1[i- 1] == s2[j- 1])dp[i][j] = 1 + dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return max(0,dp[n1][n2]);
        
    }
};
