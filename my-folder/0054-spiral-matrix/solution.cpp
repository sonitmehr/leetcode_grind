class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        

        int di = 0,x = 0,y = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        for(int i= 0;i<m*n;i++){
            ans.push_back(mat[x][y]);

            int newX = x + dx[di];
            int newY = y + dy[di];
            vis[x][y] = 1;
            if(newX >= 0 && newX < n && newY >=0 && newY < m && vis[newX][newY]==0){
                x=newX;
                y=newY;
            }
            else{
                di = (di + 1) % 4;
                x += dx[di];
                y += dy[di];
            }
        }
        return ans;
    }
};
