class Solution {
public:
    int vis[51][51];
    bool valid(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    void dfs(int i, int j,int n,int m,int oldCol,int newCol,vector<vector<int>>& image){
        vector<int> a = {-1,1,0,0},
                    b = {0,0,-1,1};
        image[i][j] = newCol;
        for(int k = 0;k<=3;k++){
            int newI = i + a[k],newJ = j + b[k];
            if(valid(newI,newJ,n,m) && image[newI][newJ] == oldCol && vis[newI][newJ] == 0){
                vis[newI][newJ] = 1;
                //image[newI][newJ] = newCol;
                dfs(newI,newJ,n,m,oldCol,newCol,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        //image[sr][sc] = color;
        dfs(sr,sc,n,m,image[sr][sc],color,image);
        return image;
    }
};
