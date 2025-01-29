#define pi pair<int, pair<int, int>>

class Solution {
public:
    bool isCyclicUtil(int v, vector<int> adj[],vector<bool> &visited,
                      int parent) {

        visited[v] = true;

        for (int i : adj[v]) {

            if (!visited[i]) {
                if (isCyclicUtil(i, adj, visited, v))
                    return true;
            }

            else if (i != parent)
                return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n + 1];
        
        for (auto& i : edges) {
            int a = i[0], b = i[1];
            vector<bool> vis(n + 1,0);
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(adj[a].size() > 0 && adj[b].size() > 0 && isCyclicUtil(a,adj,vis,b)){
                return i;
            }
            
        }
return {};
    }
};
