class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        int n = v.size();
        map<int,int> m;
        for(int i = 0;i<n;i++){
            v[i] -= i;
            m[v[i]] ++;
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int maxi = n - i;
            
            ans += (maxi - m[v[i]]);
            m[v[i]]--;
            
        }
        
        
        
        
        
        return ans;
        
        
    }
};
