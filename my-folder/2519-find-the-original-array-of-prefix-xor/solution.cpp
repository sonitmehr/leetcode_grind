class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        ans.push_back(v[0]);
        int prev= v[0];
        int xori = v[0];
        for(int i = 1;i<n;i++){
            xori = prev ^ v[i];
            ans.push_back(xori);
            prev = v[i];
            
        }
        return ans;
    } // 5 (101)^ x (111) = 2 (010)
};
