class Solution {
public:
    int dp[101];
    int f(int i,vector<int> &a){
        if(i >= a.size())return 0;
        
        if(dp[i] != -1)return dp[i];
        int pick = a[i] + f(i+2,a);
        int noPick = f(i+1,a);

        return dp[i]=max(pick,noPick); 
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};
