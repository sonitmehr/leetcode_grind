class Solution {
public:
    vector<pair<int,int>> adj[100001];
    int minScore(int n, vector<vector<int>>& roads) {
        
        for(auto i : roads){
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
            
        }
        
        queue<int> q;
        q.push(1);
        vector<int> vis(n + 1,0);
        int ans = 1e9;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(vis[node] == 1)continue;
            vis[node] = 1;
            for(auto p : adj[node]){
                if(vis[p.second] == 0){
                    ans = min(ans,p.first);
                    q.push(p.second);
                }
                
            }
        }
        return ans;
    }
};
