class Solution {
public:
    int dp[11][200][2];
    int f(string &num,int n,int sum,int tight){
        if(n == num.size()){
            return sum;
        }

        int ans = 0;
        int ub = tight ? num[n] - '0' : 9;
        if(dp[n][sum][tight] != -1)return dp[n][sum][tight];
        for(int i = 0;i<=ub;i++){
            // int newTight=num[n]==i?tight:0;
            if(i == 1){
                ans += f(num,n + 1,sum + 1,tight&(i == ub));
            }
            else ans += f(num,n+1,sum,tight&(i == ub));    
        }
        return dp[n][sum][tight] = ans;
    }
    // 13
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        return f(s,0,0,1);
    }
};
 // 4567
