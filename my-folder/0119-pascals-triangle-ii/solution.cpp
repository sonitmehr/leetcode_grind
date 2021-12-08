class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r;
        r.push_back({1});
        r.push_back({1,1});
        for (int i = 2;i<rowIndex+1;i++){
            vector<int> temp(r[r.size()-1].size()+1);
            
            temp[0] = 1;
            temp[temp.size()-1] = 1;
            
                                       
            for(int j = 1;j<temp.size()-1;j++){
                temp[j] = r[i-1][j-1] + r[i-1][j];
                
                
            }r.push_back(temp);
        }return r[rowIndex];
        
    }
};
