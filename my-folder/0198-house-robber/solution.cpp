class Solution {
public:
    
    int f(int i,int money,vector<int> &a,vector<int>&dp){
        //if(i >= a.size())return 0;
        if(i < 0)return 0;
        if(i == 0){
            return a[i];
        }
        if(dp[i]!=-1)return dp[i];
        int pick = a[i] + f(i-2,money + a[i],a,dp);
        int noPick = f(i-1,money,a,dp);
        return dp[i] = max(pick,noPick);
    }
    
    int rob(vector<int>& a) {
        vector<int> dp(a.size(),-1);
        
        return f(a.size()-1,0,a,dp);
    }
};
