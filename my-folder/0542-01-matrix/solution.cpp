#define pi pair<pair<int,int>,int>
class Solution {
public:
    int n,m;
    bool check(int i,int j){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size(),m =mat[0].size();
        vector<vector<int>> dist(n ,vector<int> (m ,1e9));
        vector<vector<int>> vis(n ,vector<int> (m ,0));

        queue<pi> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int currX = p.first.first;
            int currY = p.first.second;
            int distance = p.second;
            // dist[i][j] = min(dist[i][j],distance + 1);

                    vis[currX][currY] = 1;
            for(int k = 0;k<=3;k++){
                int newX = currX + dx[k];
                int newY = currY + dy[k];

                if(check(newX,newY) && vis[newX][newY] == 0){
                    dist[newX][newY] = min(dist[newX][newY],distance + 1);
                    q.push({{newX,newY},distance + 1});
                }
            }
        }
        

        return dist;

    }
};
