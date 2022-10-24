class Solution {
public:
    int subarrayGCD(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int g = v[i];
            for(int j = i;j<n;j++){
                g = __gcd(g,v[j]);
                if(g == k)ans++;
            }
        }
        return ans;
    }
};
