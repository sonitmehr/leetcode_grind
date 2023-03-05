class Solution {
public:
    int power(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        
        int low = ranges[0][0], high =ranges[0][1];
        int cnt = 1;
        
        for(int i= 1;i<ranges.size();i++){
            int a = ranges[i][0];
            if(a >= low && a <= high){
                high = max(high,ranges[i][1]);
            }
            else{
                low = ranges[i][0];
                high = ranges[i][1];
                cnt++;
            }
        }
        int M = 1e9+7;
        return power(2,cnt,M);
    }
};
