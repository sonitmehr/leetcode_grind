#define pii pair<int,int>
class Solution {
public:

    bool check(int i,int j,int n,int m){
        return i >= 0 && i< n && j >= 0 && j < m;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        deque<pii> q;
            int mini = 1e9;
        q.push_front({0,0});
        vector<vector<int>> cost(n,vector<int> (m,1e9));
        cost[0][0] = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            int x = p.first;
            int y = p.second;

        
            for(int k = 0;k<=3;k++){
               
                int newX = x + dx[k];
                int newY = y + dy[k];

                if(check(newX,newY,n,m)){
                    if(grid[x][y] == (k + 1) && cost[newX][newY] > cost[x][y]){
                        // cout << "cost stays same -> " << c<< " : " << x << " " << y << " : " << newX << " " << newY <<endl;
                        cost[newX][newY] = cost[x][y];
                        q.push_front({newX,newY});
                    }
                    else if(cost[newX][newY] > cost[x][y] + 1){
                        // cout << "cost increases -> " << c + 1<< " : " << x << " " << y << " : " << newX << " " << newY <<endl;
                        cost[newX][newY] = cost[x][y] + 1;
                        q.push_back({newX,newY});
                    }
                }
            }
        }
        return cost[n - 1][m - 1];
    }
};
