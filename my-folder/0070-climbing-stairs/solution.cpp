class Solution {
public:
    vector<int> dp;
    int f(int i,int n){
        if(i > n)return 0;
        if(i == n)return 1;
        if(dp[i]!=-1)return dp[i];
        int l = f(i+1,n);
        int r = f(i + 2,n);
        return dp[i] =l + r;       
        
    }
    
    int climbStairs(int n) {
        dp.resize(50);
        fill(dp.begin(),dp.end(),-1);
        return f(0,n);
    }
};
