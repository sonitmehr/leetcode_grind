class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        r.push_back({1});
        if(numRows == 1){
            return r;
            
        }
        r.push_back({1,1});
        if(numRows == 2){
            return r;
            
        }
        
        
        for(int i = 2;i<numRows;i++){
            vector<int> temp(r[r.size()-1].size()+1);// size(temp) = size(r) + 1
            temp[0] = 1;
            temp[temp.size()-1] = 1;
            
            
            for(int j = 1;j<temp.size()-1;j++){ // always adds elements from index 1
                temp[j] = r[i-1][j-1] + r[i-1][j]; // makes sure to add consecutive elements.
                                
                
            }r.push_back(temp);
        }return r;
        
        
        
    }
};
