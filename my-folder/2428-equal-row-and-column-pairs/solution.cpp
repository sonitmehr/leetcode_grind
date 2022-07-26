class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> vertical(n,vector<int> (n));
        for(int i = 0;i<n;i++){
            
            for(int j =0;j<n;j++){
                vertical[i][j] = grid[j][i] ;
                cout <<  grid[j][i] << endl;
            }
        }int cnt = 0; 
        for(int i = 0;i<n;i++){
            vector<int> curr = grid[i];
            for(int j =0;j<n;j++){
                if(vertical[j] == curr)cnt++;
            }
        }
        return cnt;
    }
};
