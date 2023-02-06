class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>&a){
        if(i >= a.size() || j >= a[i].size())return 1e9;

        if(i == a.size() -1)return a[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int one = a[i][j] + f(i + 1,j,a);
        int two = a[i][j] + f(i + 1,j + 1,a);

        return dp[i][j] = min(one,two);



    }

    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,triangle);
    }
};
