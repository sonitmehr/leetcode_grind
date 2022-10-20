class Solution {
public:
    
    int f(int i,int stop,vector<int> &dp,vector<int> &a){
        if(i < stop)return 0;
        if(i == stop)return a[i];
        if(dp[i]!=-1)return dp[i];
        
        
        int l = a[i] + f(i-2,stop,dp,a);
        int r = f(i-1,stop,dp,a);
                
        return dp[i]=max(l,r);
    }
    int rob(vector<int>& a) {
        int n = a.size();
        
        vector<int> dp(n,-1);
        if (n < 2) return n ? a[0] : 0;
        int l = f(n-1,1,dp,a);
        fill(dp.begin(),dp.end(),-1);
        int r = f(n-2,0,dp,a);
        return max(l,r);
    }
};
