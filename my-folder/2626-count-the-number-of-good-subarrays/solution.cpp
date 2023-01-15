class Solution {
public:
    long long countGood(vector<int>& v, int k) {
        long long n = v.size();
        
        long long i = 0,j = 0;
        map<long long,long long> m;
        long long cnt = 0,ans = 0;
        while(j < n){
            m[v[j]]++;
            if(m[v[j]] > 1)cnt+=(m[v[j]] - 1);
            while(i <=j && cnt >= k){
                ans += (n - j); // all to the left after cnt == k;
                m[v[i]]--;
                if(m[v[i]] >= 1)cnt -= (m[v[i]]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
