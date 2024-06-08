class Solution {
public:

    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp){

        // if()
        if(i < 0 && j>=0){
            for(int k = j;k>=0;k--){
                if(p[k] !='*')return false;
            }
            return true;
        }
        if(j < 0){
            if(i < 0)return true;
            return false;
        }
        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i - 1,j - 1,s,p,dp);
        }
        if(p[j] == '*'){
            return  dp[i][j] =solve(i - 1,j,s,p,dp) | solve(i,j - 1,s,p,dp);
        }

        return dp[i][j] =false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        
        dp[0][0] = 1;

        int k = 1;
        while(p[k - 1] == '*' && k <= m){
            dp[0][k] = 1;
            k++;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else{
                    if(p[j - 1] == '*'){
                        dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                    }
                    else dp[i][j] = 0;

                }
            }
        }

        // for(int i= 0;i<=n;i++){
        //     for(int j = 0;j<=m;j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return dp[n][m];



    }
};
