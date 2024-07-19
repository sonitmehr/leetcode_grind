class Solution {
public:

   

    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();


        vector<vector<int>> dp(n,vector<int> (n,1e9));

        dp[0][0] = a[0][0];

        for(int i = 1;i<n;i++){
            for(int j = 0;j<=i;j++){
                int top = 1e9,left = 1e9;
                top = dp[i - 1][j];
                if(j - 1 >= 0)left = dp[i - 1][j - 1];

                dp[i][j] = a[i][j] + min(top,left);
            }
        }
        // for(auto &i : dp[n - 2])cout << i << " ";
        // cout << endl;
        // for(auto &i : dp[n - 1])cout << i << " ";
        return *min_element(dp[n - 1].begin(),dp[n - 1].end());


    }
};
