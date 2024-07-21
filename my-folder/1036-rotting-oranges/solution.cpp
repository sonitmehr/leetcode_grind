class Solution {
public:

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};

    bool check(int i, int j,int n,int m ){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int rotten = 0,ans = 0;
    void solve(int i, int j,vector<vector<int>> &mat,int n,int m){
        
        
    }

    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int orange = 0;

        
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(mat[i][j] == 2){
                    q.push({{i,j},0});
                    orange++;
                }
                if(mat[i][j] == 1)orange++;
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int x = p.first.first;
            int y = p.first.second;
            int time = p.second;
            ans=max(ans,time);
            cout << x << " " << y << " " << time << endl;
            rotten ++;
            for(int k = 0;k<=3;k++){
                int newX = x + dx[k];
                int newY = y + dy[k];

                if(check(newX,newY,n,m) && mat[newX][newY] == 1){
                    mat[newX][newY] = 3;
                    q.push({{newX,newY},time + 1});
                }

            }



        }
        cout << rotten << " " << orange << endl;
        return rotten == orange ? ans : -1;


    }
};
