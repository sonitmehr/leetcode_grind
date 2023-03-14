class Solution {
public:
    long long beautifulSubarrays(vector<int>& v) {
        int n = v.size();
        vector<int> pre(n + 1);

        for(int i = 0;i<n;i++){
            pre[i + 1] = pre[i]^v[i];
        }
        
        map<int,int> m;
        m[0]++;
        long long ans = 0;
        for(int i  = 1;i<=n;i++){
            ans += m[pre[i]];
            m[pre[i]]++;
        }
        return ans;
    }
};
