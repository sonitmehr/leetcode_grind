class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, int parent,int stp,vector<int>&vis,vector<int>&step,vector<int> &low,vector<int> adj[]){

        vis[i] = 1;
        step[i] = stp;
        low[i] = stp;
        for(auto &adjNode : adj[i]){
            if(adjNode == parent)continue;
            if(vis[adjNode] == 0){
                dfs(adjNode,i,stp + 1,vis,step,low,adj);
                low[i] = min(low[i],low[adjNode]);
                if(low[adjNode] > step[i]){
                    ans.push_back({i,adjNode});
                }

            }
            else{
                int adjLow = low[adjNode];
                low[i] = min(low[i],adjLow);
            }
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        ans.clear();
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> step(n);
        vector<int> low(n);
        vector<int> vis(n,0);

        dfs(0,-1,0,vis,step,low,adj);
        return ans;
    }
};
