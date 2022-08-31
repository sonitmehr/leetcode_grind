class Solution {
public:
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 && v[i][j] == '1'){
                    cnt++;
                    queue<pair<int,int>> q;
                    vis[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> node = q.front(); 
                        q.pop();
                        int I = node.first;
                        int J = node.second;
                        if(I < n && I >= 0 && J < m && J >= 0){
                            if(I -1 >=0 && vis[I -1][J] == 0 && v[I -1][J] == '1'){
                                q.push({I-1,J});
                                vis[I -1][J] =1;
                            }
                            if(I+1 < n && vis[I + 1][J] == 0 && v[I + 1][J] == '1'){
                                q.push({I +1,J});
                                vis[I +1][J] =1;
                            }
                            if(J-1 >=0 && vis[I][J - 1] == 0 && v[I][J - 1] == '1'){
                                q.push({I,J -1});
                                vis[I][J -1] =1;
                            }if(J+1 <m && vis[I][J + 1] == 0 && v[I][J + 1] == '1'){
                                q.push({I,J+1});
                                vis[I][J +1] =1;
                            }
                        }                       
                        
                    }
                
                    
                }
            }
        }
        return cnt;
    }
};
