class Solution {
public:

    int dfs(int node,int p,vector<int> adj[],vector<bool>& apple){
        int time = 0;
        for(auto child : adj[node]){
            if(child != p){
                int childTime = dfs(child,node,adj,apple);
                if(childTime > 0 || apple[child]){
                    time += 2 + childTime ;
                }
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n+1];
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,0,adj,hasApple);

    }
};
