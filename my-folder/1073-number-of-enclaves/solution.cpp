class Solution {
public:
bool valid(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    bool border(int i,int j,int n,int m){
        if(i == n - 1 || j == m - 1 || i == 0 || j == 0)return true;
        return false;
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        
        // for(int i = 0;i<n;i++){
        //     if(mat[i][0] == 'O')q.push({i,0});
        //     if(mat[i][m - 1] == 'O')q.push({i,m - 1});

        // }
        // for(int j = 0;j<m;j++){
        //     if(mat[0][j] == 'O')q.push({0,j});
        //     if(mat[n - 1][j] == 'O')q.push({n-1,j});
        // }
        vector<int> a = {-1,1,0,0},
        b = {0,0,-1,1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(border(i,j,n,m) && mat[i][j] == 1){
                    q.push({i,j});
                    //cout << i << " " << j << endl;
                    while(!q.empty()){
                        auto p = q.front();
                        q.pop();
                        int I = p.first,J = p.second;
                        if(vis[I][J] == 1)continue;
                        vis[I][J] = 1;
                        for(int k = 0;k<=3;k++){
                            int newI = I + a[k],newJ = J + b[k];
                            if(valid(newI,newJ,n,m) && mat[newI][newJ] == 1 && vis[newI][newJ] == 0){
                                
                                q.push({newI,newJ});   
                            }
                        }
                    }
                    // for(int i = 0;i<n;i++){
                    //     for(int j = 0;j<m;j++){
                    //         cout << vis[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }
                }
            }
        }
        int ans= 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
                //cout << vis[i][j] << " ";
            }
            //cout << endl;
        }
        return ans;
    }
};
