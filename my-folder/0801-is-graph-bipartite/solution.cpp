class Solution {
public:
    int color[101];
    int vis[101];
    vector<int> adj[101];
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

    bool isBipartite(vector<vector<int>>& graph) {
        for(int i = 0;i<graph.size();i++){
            for(auto j : graph[i]){
                adj[i].push_back(j);
                //adj[j].push_back(i);
            }
            
            
        }
        queue<pair<int,int>> q;
        for(int i = 0;i<graph.size();i++){
            if(vis[i] == 0){
                q.push({i,0});

                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    int currNode = p.first;
                    int c = p.second;
                    if(vis[currNode] == 1)continue;
                    vis[currNode ] = 1;
                    color[currNode] = c;
                    for(auto node : adj[currNode]){
                        if(vis[node] == 0){
                            q.push({node,c^1});
                        }
                        else if(color[node ] == color[currNode]){
                            return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }
};
