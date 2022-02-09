class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        
        if(numRows == 0){
            return v;
        }
        
        vector<int> v1;
        v1.push_back(1);
        v.push_back(v1);
        
        for(int i =1;i<numRows;i++){
            vector<int> prevRow = v[i-1];
            vector<int> currRow;
            
            currRow.push_back(1);
            for(int j = 1;j<i;j++){
                currRow.push_back(prevRow[j]+prevRow[j-1]);                                
            }
            currRow.push_back(1);
            v.push_back(currRow);
        }
        return v;
        
    }
};
