class Solution {
public:
    
    void f(int i, int j,int startColor,int color,vector<vector<int>> &a,vector<vector<int>>&vis){
        if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size())return;
        
        
        if(vis[i][j] == 0 && a[i][j] == startColor){
            a[i][j] = color;
            vis[i][j] = 1;
            f(i-1,j,startColor,color,a,vis);
            f(i+1,j,startColor,color,a,vis);
            f(i,j-1,startColor,color,a,vis);
            f(i,j+1,startColor,color,a,vis);
        }
        
        //[[0,0,0],
        // [0,0,0]]
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int newColor) {
        vector<vector<int>> vis(a.size(),vector<int>(a[0].size(),0));
        
        f(sr,sc,a[sr][sc],newColor,a,vis);
        return a;
    }
};
