class Solution {
public:
    
    int f(int i, vector<int> &a, vector<int> &dp){
        if(i  >= a.size() -1)return 0;
        if(dp[i]!=-1)return dp[i];        
        
        int pick = 1e9;
        for(int ii= 1;ii<=a[i];ii++){
            int ele = 1 + f(i + ii,a,dp);
            pick = min(pick,ele);
        }
        return dp[i] = pick;        
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,-1);
        
        return f(0,nums,dp);
    }
};
