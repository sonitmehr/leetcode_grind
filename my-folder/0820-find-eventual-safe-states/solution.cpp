class Solution {
public:
    int vis[10001];
    int path[10001];
    map<int,int> m;
    bool f(int node,vector<vector<int>>& adj){
        vis[node] = 1;
        path[node] = 1;

        for(auto i : adj[node]){
            if(vis[i] == 0){
                if(f(i,adj) == false)return false;
            }
            else if(path[i])return false;
        }
        m[node] = 1;
        path[node] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
        for(int i = 0;i<adj.size();i++){
            if(vis[i] == 0){
                f(i,adj);
            }
        }
        vector<int> ans;
        for(int i = 0;i<adj.size();i++){
            if(m[i] == 1)ans.push_back(i);
        }
        return ans;
    }
}; 
