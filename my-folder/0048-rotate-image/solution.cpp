class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        
        for(int i = 0;i<n/2;i++){
            for(int j = i;j<n-i-1;j++){
                
                int curr = v[i][j];
                
                int dest = v[j][n - i -1];
                
                v[j][n - i - 1] = curr;
                curr = v[n-i-1][n-j-1];
                v[n-i-1][n-j-1] = dest;
                dest = v[n-j-1][i];
                v[n-j-1][i] = curr;
                curr = v[i][j];
                v[i][j] = dest;                
                
            }
        }
        
    }
};
