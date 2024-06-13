#define pi pair<pair<int,int>,int>
class Solution {
public:
bool check( int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();

        int cnt = 0;
        queue<pi> q;
vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1)cnt++;
            }
        }
        int maxTime = 0;
        while(!q.empty()){
            pi top = q.front();
            q.pop();

            int currX = top.first.first;
            int currY = top.first.second;
            int time = top.second;
            maxTime = max(maxTime,time);
            for(int k = 0;k<=3;k++){
                int newX = currX + dx[k];
                int newY = currY + dy[k];
                if(check(newX,newY,n,m) && grid[newX][newY] == 1){
                // cout << newX << " " << newY << endl;
                    q.push({{newX,newY},time+ 1});
                    grid[newX][newY] = 2;
                    cnt--;
                }
            
            
            }
        }
        return cnt == 0 ? maxTime : -1;
        
        

    }
};
