class Solution {
public:
    int minimumOperations(vector<int>& v) {
        sort(v.begin(),v.end());
        int n  = v.size();
        map<int,int> m;
        
        for(int i = 0;i<n;i++){
            if(v[i]!=0)m[v[i]]++;
        }
        return m.size();
    }
};
