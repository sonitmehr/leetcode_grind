class Solution {
public:
    string s1,s2;

    int dp[1001][1001];
    int f(int i,int j){ 
        if(j < 0)return 1;
        if( i < 0)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] =f(i-1,j-1) + f(i-1,j);
        }
        return dp[i][j] = f(i - 1,j);
    }
    int numDistinct(string s, string t) {
        s1 = s,s2 = t;
        int n1 = s1.size(),n2 = s2.size();
        memset(dp,-1,sizeof(dp));
        return f(n1-1,n2-1);
    }
};
