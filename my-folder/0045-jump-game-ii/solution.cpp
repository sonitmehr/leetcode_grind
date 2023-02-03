class Solution {
public:
    int dp[10001];
    int minJumps;
    int f(int i,vector<int>&a,int jumps){
        if(i >= a.size()-1)return 0;
        // if(i == a.size() -1){
            
        //     return jumps;
        // }
        if(dp[i] != -1)return dp[i];
        //cout << i << " " << jumps << endl;

        int one = 1e9,mini = 1e9;
        for(int ind = 1;ind<=a[i];ind++){
            one =  min(one,1 + f(i + ind,a,jumps + 1));
            mini = min(one,mini);
        }
        return dp[i] = one;
    }

    int jump(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        minJumps =1e9;
        return f(0,a,0);
        
    }
};
