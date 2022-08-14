class Solution {
public:
    int edgeScore(vector<int>& v) {
        int n = v.size();
        map<long,long> m;
        long maxi = -1;
        for(int i = 0;i<n;i++){
            m[v[i]] += (i);
            maxi = max(maxi,m[v[i]]);
        }
        long ans = 1e9;
        for(auto i : m){
            if(i.second == maxi){
                ans = min(ans,i.first);
            }
        }
        return ans;
    }
};
