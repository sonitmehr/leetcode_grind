class Solution {
public:
    int dp[101][1001][2];
    int M = 1e9 + 7;
    int f(string &num,int n,int x,int tight,int min_sum,int max_sum){
        if(n >= num.size()){
            if(x >= min_sum && x <= max_sum)return 1;
            return 0;
        }
        if(x > max_sum )return  0;
        if(dp[n][x][tight] != -1)return dp[n][x][tight];
        
        long long ans = 0;
        
        
        int ub = (tight) ? num[n] - '0' : 9;
        //cout << "Hello";
        for(int dig = 0;dig <= ub;dig++){
            ans = (ans + f(num,n + 1,x + dig,tight&(dig == ub),min_sum,max_sum))%M;
        }
        return dp[n][x][tight] = ans%M;
        
        
    }
    
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int left=  0,right = 0;
        int n1= num1.size(),n2 = num2.size();
        
        left = f(num1,0,0,1,min_sum,max_sum);
            memset(dp,-1,sizeof(dp));
        right = f(num2,0,0,1,min_sum,max_sum);
        
        int add= 0;
        
        int sum = 0;
        for(auto &i : num1){
            sum += (i - '0');
        }
        if(sum >= min_sum && sum <= max_sum)add = 1;
        

        
        
        return right - left + add;
    }
};
