#define pb push_back
class Solution {
public:
    int maxJump(vector<int>& v) {
        int n = v.size();
        if(n == 2){
            return max(v[0],v[1]);
        }
        vector<int> paths;
        for(int i = 0;i<n-2;i+=2){
            paths.pb(v[i + 2] - v[i]);
        }
        
        for(int i = 1;i < n - 2;i+=2){
            paths.pb(v[i + 2] - v[i]);
        }
        sort(paths.begin(),paths.end());
        return max(v[1] - v[0],paths.back());
    }
};
