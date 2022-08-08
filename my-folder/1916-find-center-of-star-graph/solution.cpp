class Solution {
public:
    int findCenter(vector<vector<int>>& v) {
        if(v[0][0] == v[1][0] || v[0][0] == v[1][1]){
            return v[0][0];
        }
        return v[0][1];
        
        
        
    }
};
