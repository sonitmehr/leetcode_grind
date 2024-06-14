class Solution {
public:
    int n,m;
    bool check(int i,int j){
        if(i < 0 || j <0 || i >=n || j >=m)return false;
        return true;
    }
vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &vis,char c,vector<vector<char>>  &mat){
        cout << i<< " " << j << endl;
        vis[i][j] = 1;

        for(int k = 0;k<=3;k++){
                int newX = i + dx[k];
                int newY = j + dy[k];

            if(check(newX,newY) && vis[newX][newY] == 0 && mat[newX][newY] == 'O'){
                mat[newX][newY] = c;
                dfs(newX,newY,vis,c,mat);
                // q.push({{newX,newY},distance + 1});
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        n = mat.size(),m = mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(mat[i][0] == 'O'){
                dfs(i,0,vis,'O',mat);
            }
            if(mat[i][m - 1] == 'O'){
                dfs(i,m-1,vis,'O',mat);
            }
        }
        for(int i = 0;i<m;i++){
            if(mat[0][i] == 'O'){
                dfs(0,i,vis,'O',mat);
            }
            if(mat[n - 1][i] == 'O'){
                dfs(n - 1,i,vis,'O',mat);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] ='X';
                    dfs(i,j,vis,'X',mat);
                }
            }
        }
    }
};
