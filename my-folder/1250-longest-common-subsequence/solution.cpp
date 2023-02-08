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

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        int n1 = s1.size(),n2 = s2.size();
        // for(int i =0;i<n2;i++)dp[i][0] = 0;
        // for(int i = 0;i<n1;i++)dp[0][i] = 0;
        // for(int i= 0;i<=n1;i++){
        //     for(int j= 0;j<=n2;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for(int i = 1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                if(s1[i - 1] == s2[j - 1])dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
        // cout << endl;
        // for(int i= 0;i<=n1;i++){
        //     for(int j= 0;j<=n2;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n1][n2];
    }
};
