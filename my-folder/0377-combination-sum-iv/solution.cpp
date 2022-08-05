class Solution {
public:
    
    int f(int i,vector<int> &a,vector<vector<int>> &ans,int target,vector<int> &v,vector<int> &dp){
        if(target < 0)return 0;
        if(target == 0)return 1;
        
        int l = 0;
        
        if(dp[target] != -1)return dp[target];
        
        for(int ii = 0;ii<a.size();ii++){
            
            if(a[ii] > target)continue;
            
            l += f(ii,a,ans,target - a[ii],v,dp);
            
            //v.pop_back();
            //(ii+1,a,ans,target,v);
        }
        return dp[target] = l;
        
        
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        int l = 0;
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return f(0,nums,ans,target,v,dp);
        
        
    }
};
