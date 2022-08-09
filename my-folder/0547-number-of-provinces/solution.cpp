class Solution {
public:
    
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj){
        vis[i] = 1;
        
        for(int node = 0;node< adj.size();node++){
            if(vis[node] ==0 && adj[i][node] == 1){
                dfs(node,vis,adj);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        
        
        vector<int> vis(n + 3,0);
        
//         for(int i =0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 int a = i + 1;
//                 int b = j + 1;
//                 if(adj[i][j] == 1){
//                     newAdj[a].push_back(b);
                    
//                 }
//             }
//         }
        
        // for(auto i : newAdj){
        //     for(auto j : i)cout << j << " ";
        //     cout << endl;
        // }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
