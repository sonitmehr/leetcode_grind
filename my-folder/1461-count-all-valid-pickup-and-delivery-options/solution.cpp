/*class Solution {
public:
    int M = 1e9 + 7;
    long long mod(long long n){
        return (n%M+ M)%M;
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
    
    int countOrders(int n) {
        vector<long long> f(505);
        f[0]=1;f[1]=1;
        for(int i = 2;i<=200;i++)f[i] = mul(f[i-1],(long long)i);
        vector<long long> x(505);
        x[0]=1;
        for(int i =1;i<500;i++)x[i] = mul(x[i-1],2LL*(i+1)-1);
        return mul(f[n],x[n-1]);
    }
};*/
class Solution {
public:
    int countOrders(int n) {
        long res = 1, mod = 1000000007;
        for(int i = 1; i <=n; ++i)
        {
			// calulating n!
            res *= i;
			// to avoid overflow
            res %= mod;
			
			// (2*i-1) are the vacant places which we can choose
			// later we have n! permutation of pickup task
			// therefore we have to multiply with n! that we calculated as res.
            res *= (2*i-1);
			
			// to avoid overflow
            res %= mod;
        }
        
		// to avoid overflow
        return res % mod;
    }
};
