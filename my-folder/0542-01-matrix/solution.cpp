class Solution {
public:
    /*
    [[0,1,0],
     [0,1,0],
     [0,1,0],
     [0,1,0],
     [0,1,0]]
    */
    bool valid(int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e9));
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
                //lse ans[i][j] = 0;
            }
        }
        while(!q.empty()){
            auto p = q.front();
            vector<int> a = {-1,1,0,0},b = {0,0,-1,1};
            int i = p.first.first;
            int j = p.first.second;
            int dist = p.second;
            q.pop();
            vis[i][j] = 1;
            bool flag = false;
            if(mat[i][j] == 1)ans[i][j] = min(ans[i][j],dist);
            for(int k = 0;k<=3;k++){
                int newI = i + a[k],newJ = j + b[k];
                if(valid(newI,newJ,n,m) && vis[newI][newJ] == 0){
                    q.push({{newI,newJ},dist+1});
                }
            }
            

        }
        return ans;


    }
};
