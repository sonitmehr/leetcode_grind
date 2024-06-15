#define pi pair<int,pair<int,int>>
#define pii pair<int,int>
class Solution {
public:


bool check(int i,int j,int n,int m){
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    return true;
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pii> adj[n];
        for(int i = 0;i<flights.size();i++){
            int a = flights[i][0];
            int b = flights[i][1];
            int d = flights[i][2];
            adj[a].push_back({b,d});
        }
        // priority_queue<pi,vector<pi>,greater<pi>> q;
        queue<pi> q;
        k++;
        int ans = 1e9;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();


            int dis = p.first;
            int node = p.second.first;
            int currK = p.second.second;

            if(currK <= k && node == dst){
                ans = min(ans,dis);
            }

            for(auto &i : adj[node]){
                int adjNode = i.first;
                int adjDist = i.second;
                // cout << dis << " " << adjDist << ' ' << adjNode << endl;
                if(dist[adjNode] > dis + adjDist){
                    dist[adjNode] = dis + adjDist;
                    q.push({dis + adjDist,{adjNode,currK + 1}});
                }
            }



            
        }
        return ans == 1e9 ? -1 : ans;
    }
};
