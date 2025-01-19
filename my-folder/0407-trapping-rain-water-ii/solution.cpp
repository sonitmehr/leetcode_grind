#define pii pair<int,pair<int,int>>
class Solution {
public:

/*
[1,4,3,1,3,2],
[3,2,1,3,2,4],
[2,3,3,2,3,1]
*/
    bool check(int i, int j,int n,int m ){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int trapRainWater(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();


        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));

        // Yet to push initial values

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};
        int ans = 0;


        for(int i = 0;i<m;i++){
            pq.push({heights[0][i],{0,i}});
            vis[0][i] = 1;
            pq.push({heights[n - 1][i],{n - 1,i}});
            vis[n - 1][i] = 1;
        }
        for(int i = 1;i<n- 1;i++){
            pq.push({heights[i][0],{i,0}});
            vis[i][0] = 1;
            pq.push({heights[i][m - 1],{i,m - 1}});
            vis[i][m - 1] = 1;
        }
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int h = p.first;
            int r = p.second.first;
            int c = p.second.second;


            for(int k = 0;k<=3;k++){
                int x = r + dx[k];
                int y = c + dy[k];


                if(check(x,y,n,m) && vis[x][y] == 0){
                    int H = heights[x][y];
                    vis[x][y] = 1;

                    if(H < h){
                        pq.push({h,{x,y}});
                        heights[x][y] = h;
                        ans += (h - H);
                    }
                    else{
                        pq.push({H,{x,y}});
                    }
                }

            }
        }
        return ans;
    }
};
