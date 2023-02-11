class Solution {
public:
    int dp[1001][1001];
    string s1,s2;
    int f(int i,int j){
        if(i <0 || j < 0)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int one = 0;
        if(s1[i] == s2[j])one = 1 + f(i - 1,j - 1);
        return dp[i][j] = max({one,f(i - 1,j),f(i,j- 1)});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        s1 = word1,s2 = word2;
        int n1 = s1.size(),n2 = s2.size();
        int ans = f(n1-1,n2-1);

        return n1 - ans + n2 - ans;
    }
};
