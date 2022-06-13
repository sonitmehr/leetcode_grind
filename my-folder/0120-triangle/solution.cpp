class Solution {
public:
    
    int f(int ind,vector<vector<int>> &dp,vector<vector<int>> &a,int row,int n){
        if(ind == n-1)return a[ind][row];
        if(dp[ind][row]!=-1)return dp[ind][row];
        
        int l = a[ind][row] + f(ind +1,dp,a,row,n);
        int r = a[ind][row] + f(ind+1,dp,a,row+1,n);
        return dp[ind][row] = min(l,r);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return f(0,dp,triangle,0,triangle.size());
    }
};
