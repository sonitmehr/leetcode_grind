#define pi pair<pair<int,int>,int>
class Solution {
public:

    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool check(int i, int j,int n,int m){
        return i>=0 && j >= 0 && i < n && j < m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n,vector<int>(m,1e9));

        queue<pi> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    dis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int i = p.first.first;
            int j = p.first.second;
            int dist = p.second;

            mat[i][j] = 0;
            for(int k = 0;k<=3;k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(check(x,y,n,m) && mat[x][y] == 1){
                    mat[x][y] = 0;
                    dis[x][y] = min(dis[x][y],1 + dist);
                    q.push({{x,y},dist + 1});
                }
            }

        }
        return dis;

    }
};
