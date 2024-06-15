#define pi pair<int,pair<int,int>>

class Solution {
public:
bool check(int i,int j,int n,int m){
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    return true;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size(),m = heights[0].size();

        priority_queue<pi,vector<pi>,greater<pi>> q;


        q.push({0,{0,0}});
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0] = 0;
        while(!q.empty()){
            auto p = q.top();
            q.pop();


            int i = p.second.first;
            int j = p.second.second;
            int dis = p.first;



            for(int k = 0;k<4;k++){
                int newX = i + dx[k];
                int newY = j + dy[k];
                
                if(check(newX,newY,n,m)){
                    int diff =  max(dis,abs(heights[i][j] - heights[newX][newY]));
                    if(dist[newX][newY] > diff){
                        dist[newX][newY] = diff;
                        q.push({diff,{newX,newY}});
                    }
                }
            }
            // for(int i = 0;i<n;i++){
            //     for(int j = 0;j<m;j++){
            //         cout << dist[i][j] << " ";
            //     }
            //     cout << endl ;
            // }
            // cout << endl;
        }

            return dist[n - 1][m - 1];


    }
};
