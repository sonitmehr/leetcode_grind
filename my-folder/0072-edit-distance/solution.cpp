class Solution {
public:
    string s1,s2;
    int dp[501][501];
    int f(int i,int j){
        if(i < 0)return j + 1;
        if(j < 0)return i + 1;
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] =f(i-1,j-1);
        }
        return dp[i][j] =1 + min({f(i - 1,j),f(i,j - 1),f(i-1,j-1)});
    }

    int minDistance(string word1, string word2) {
        s1 = word1,s2 = word2;
        //memset(dp,-1,sizeof(dp));
        int n1 = s1.size(),n2 = s2.size();

        for(int i = 0;i<=n1;i++)dp[i][0] = (i);
        for(int j = 0;j<=n2;j++)dp[0][j] = (j);

        for(int i = 1;i<=n1;i++){
            for(int j= 1;j<=n2;j++){
                if(s1[i- 1] == s2[j- 1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n1][n2];
    
    }

};
