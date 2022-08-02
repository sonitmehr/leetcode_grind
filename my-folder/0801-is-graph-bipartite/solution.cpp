class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj,vector<int> &vis,vector<int> &col,int c){
        vis[node] = 1;
        col[node] = c;
        for(auto i : adj[node]){
            if(vis[i] == 0){
                
                
                if(dfs(i,adj,vis,col,c^1) == false)return false;
            }
            else if (col[node] == col[i])return false;
        }
        return true;
    }
    
    
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size(); 
        
        vector<int> vis(n+1,0);
        
        vector<int> col(n+1,-1);
        
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                if(dfs(i,adj,vis,col,0) == false)return false;
            }
        }
        
        return true;
        
    }
};
