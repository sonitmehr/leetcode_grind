class Solution {
public:

    int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        

        if(i > j)return 0;
        int mini = INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        for(int k = i;k<=j;k++){

            int steps = cuts[j + 1] - cuts[i - 1] + solve(i,k - 1,cuts,dp) + solve(k + 1,j,cuts,dp);
            mini = min(mini,steps);
        }
        return dp[i][j] =  mini;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size() + 2,vector<int>(cuts.size() + 2+2,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return solve(1,cuts.size() - 2,cuts,dp);
    }
};
