class Solution {
public:
    int M = 1e8;
    int maxScore(vector<int>& pre) {
        vector<long long> v;
        for(auto  i : pre)v.push_back(i);
        sort(v.rbegin(),v.rend());
        int n = v.size();
        for(int i= 1;i<n;i++){
            v[i] = (v[i] + v[i - 1]);
        }
        long long ans = 0;
        for(auto i : v){
            if(i > 0)ans++;
        }
        return ans;
    }
};
