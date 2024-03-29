class Solution {
public:
    int dp[501][501];
    int solve(int i,int j, string &s1,string &s2){
        
        if(i < 0)return j + 1;
        if(j < 0)return i + 1;

        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(i - 1,j - 1,s1,s2);

        return dp[i][j] = 1 + min(solve(i,j - 1,s1,s2),min(solve(i - 1,j,s1,s2),solve(i - 1,j - 1,s1,s2)));

    }

    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(n - 1,m - 1,word1,word2);
    }
};
