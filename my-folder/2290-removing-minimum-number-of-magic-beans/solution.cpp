class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long n = beans.size();
        
        sort(beans.begin(),beans.end());
        long long minAns = 1e18;
        long long sum= 0;
        for(auto i : beans) sum+=i;
        for(long long i = 0;i<n;i++){
            long long change = sum - (n-i)*(long long)beans[i]*1LL;
            minAns = min(minAns,change);
        }
        return minAns;
    }
};
