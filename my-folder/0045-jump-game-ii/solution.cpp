class Solution {
public:
    int dp[10001];
    int f(int i,vector<int>&a){
        if(i >= a.size() - 1)return 0;
        int mini = 1e9,one = 1e9;
        if(dp[i] != -1)return dp[i];
        for(int ind = 1;ind<=a[i];ind++){
            mini = min(mini,1 + f(i + ind,a));
            //mini = min(mini,one);
            //cout << mini << " " << ind << endl;
        }
        return dp[i] = mini;
    }

    int jump(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return f(0,a);
    }
};
