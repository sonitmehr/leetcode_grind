#define pii pair<int,pair<int,int>>
class Solution {
public:

    bool check(int i,int j,int n, int m){
        return i >= 0 && j >= 0 && j < m && i < n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pii> pq;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isWater[i][j] == 1){
                    pq.push({0,{i,j}});
                    vis[i][j] = 1;
                    isWater[i][j] = 0;
                }
            }
        }   

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        
        while(!pq.empty()){
            auto p = pq.front();
            pq.pop();

            int h = p.first;
            int r = p.second.first;
            int c = p.second.second;
            // cout << "In Queue : ";
            // cout << r << " " << c << endl;

            for(int k = 0;k<=3;k++){
                int x = r + dx[k];
                int y = c + dy[k];

                if(check(x,y,n,m) && vis[x][y] == 0){
                    // cout << x << " " << y << endl;
                    isWater[x][y] = h + 1;
                    vis[x][y] = 1;

                    pq.push({h + 1,{x,y}});
                }

            }
        }

        return isWater;


    }
};
