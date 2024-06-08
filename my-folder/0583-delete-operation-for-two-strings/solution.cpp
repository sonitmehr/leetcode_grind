class Solution {
public:

    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        
        if(i < 0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int one = 1e9;
        if(s1[i] == s2[j]){
            one = solve(i - 1,j - 1,s1,s2,dp);
        }
        int two = 1 + solve(i - 1,j,s1,s2,dp);
        int three = 1 + solve(i,j - 1,s1,s2,dp);

        return dp[i][j] = min(one,min(two,three));
    }

    int minDistance(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        // vector<vector<int>> dp(n + 1,vector<int> (m + 1,0));
        vector<int> prev(m + 1,0),curr(m + 1,0);
        for(int i = 0;i<=m;i++){
            prev[i] = i;
        }
        // for(int i = 0;i<=n;i++){
        //     dp[i][0] = i;
        // }

        for(int i = 1;i<=n;i++){
            curr[0] = i;
            for(int j = 1;j<=m;j++){
                if(s1[i - 1] == s2[j - 1]){
                    curr[j] = prev[j - 1];
                }
                else{
                    curr[j] = 1 + min(prev[j],curr[j - 1]);
                }
            }
            prev = curr;
        }

        return curr[m];
    }
};
