class Solution {
public:

    bool solve(int i,vector<int> adj[],vector<int> &color,int c,vector<int> &vis){

        color[i] = c;
        vis[i] = 1;
        for(auto &adjEle : adj[i]){
            
            if(color[adjEle] == c){
                return false;
            }
            else if(vis[adjEle] == 0){
                if(solve(adjEle,adj,color,c^1,vis)== false)return false;
            }

        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> adj[n];

        for(int i = 0;i<n;i++){
            for(auto &j : mat[i]){
                adj[i].push_back(j);
            }
        }
        vector<int> color(n,-1);
        vector<int> vis(n,0);

        for(int i= 0;i<n;i++){
            if(vis[i] == 0){
                if(solve(i,adj,color,1,vis) == false)return false;
            }
        }

return true;
    }
};
