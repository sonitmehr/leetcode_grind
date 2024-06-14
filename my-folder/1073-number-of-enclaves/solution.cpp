class Solution {
public:
int n,m;
    bool check(int i,int j){
        if(i < 0 || j <0 || i >=n || j >=m)return false;
        return true;
    }
vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int ans = 0;
    void dfs(int i,int j,vector<vector<int>> &vis,int c,vector<vector<int>>  &mat){
        // cout << i<< " " << j << endl;
        vis[i][j] = 1;

        for(int k = 0;k<=3;k++){
                int newX = i + dx[k];
                int newY = j + dy[k];

            if(check(newX,newY) && vis[newX][newY] == 0 && mat[newX][newY] == 1){
                mat[newX][newY] = c;
                ans ++;
                dfs(newX,newY,vis,c,mat);
                // q.push({{newX,newY},distance + 1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        n = mat.size(),m = mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(mat[i][0] == 1){
                dfs(i,0,vis,1,mat);
            }
            if(mat[i][m - 1] == 1){
                dfs(i,m-1,vis,1,mat);
            }
        }
        for(int i = 0;i<m;i++){
            if(mat[0][i] == 1){
                dfs(0,i,vis,1,mat);
            }
            if(mat[n - 1][i] == 1){
                dfs(n - 1,i,vis,1,mat);
            }
        }
        ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1 && vis[i][j] == 0){
                    mat[i][j] = 0;
                    dfs(i,j,vis,1,mat);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
