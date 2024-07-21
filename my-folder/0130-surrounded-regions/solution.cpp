class Solution {
public:

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

    bool check(int i,int j,int m,int n){
        return i>=0 && j >= 0 && i< n  &&j<m;
    }

    void dfs(int i, int j,vector<vector<char>> &mat,vector<vector<int>> &vis,int n,int m){
        vis[i][j] = 1;

        mat[i][j] = 'X';
        for(int k = 0;k<=3;k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(check(x,y,m,n) && mat[x][y] == 'O'){
               dfs(x,y,mat,vis,n,m);
                mat[x][y] = 'X';
                
            } 
        }
    }

    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<m;i++){
            if(mat[0][i] == 'O'){
                dfs(0,i,mat,vis,n,m);
            }
            if(mat[n - 1][i] == 'O'){
                dfs(n - 1,i,mat,vis,n,m);

            }
        }

        for(int i = 0;i<n;i++){
            if(mat[i][0] == 'O'){
                dfs(i,0,mat,vis,n,m);
            }
            if(mat[i][m - 1] == 'O'){
                dfs(i,m-1,mat,vis,n,m);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 1){
                    mat[i][j] = 'O';
                }
                if(vis[i][j] == 0 && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }


    }
};
