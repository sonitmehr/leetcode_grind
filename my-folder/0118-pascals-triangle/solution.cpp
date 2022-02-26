class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.push_back({1});
        if(numRows == 1)return v;
        v.push_back({1,1});
        if(numRows == 2)return v;
        for(int i = 2;i<numRows;i++){
            vector<int> col(v[v.size()-1].size()+1);
            col[0]=1;
            col[col.size()-1] = 1;
            for(int j = 1;j<col.size()-1;j++){
                col[j] = v[i-1][j-1] + v[i-1][j];
            }
            
            v.push_back(col);
        }
        return v;
    }
};
