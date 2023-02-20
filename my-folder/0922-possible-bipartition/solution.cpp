class Solution {
public:
    int color[2001];
    int vis[2001];
    vector<int> adj[2001];
    bool f(int node,int c){
        vis[node] = 1;
        color[node] = c;
        for(auto i : adj[node]){
            if(vis[i] == 0){
                if(f(i,c^1) == false)return false;
            }
            else if(color[node] == color[i])return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& graph) {
        for(int i = 0;i<graph.size();i++){
            adj[graph[i][0]].push_back(graph[i][1]);
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                if(f(i,0) == false)return false;
            }

        }
        return true;


    }
};
