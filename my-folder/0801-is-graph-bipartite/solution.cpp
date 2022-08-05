class Solution {
public:
    
    bool dfs(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &col,int c){
        vis[i] = 1;
        col[i] = c;
        
        for(auto ii : adj[i]){
            if(vis[ii] == 0){
                if(dfs(ii,adj,vis,col,c^1) == false)return false;
            }else if(col[i] == col[ii])return false;
            
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n + 1,0);
        vector<int> col(n + 1,-1);
        int c = 0;
        
        
        for(int i = 0;i <n;i++){
            if(vis[i]==0){
                if(dfs(i,graph,vis,col,c) == false)return false;
            }
        }
        return true;
    }
};
