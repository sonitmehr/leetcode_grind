class Solution {
public:

    void dfs(int i,vector<int> &vis,vector<int> adj[]){

        vis[i] = 1;

        for(auto adjEle : adj[i]){
            if(vis[adjEle] == 0){
                dfs(adjEle,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n + 1,0);
        vector<int> adj[n + 1];

        for(int i = 0;i<n;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 1){
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(vis[i] == 0){
                dfs(i,vis,adj);
                ans++;
            }
        }

        return ans;


    }
};
