class Solution {
public:
    int vis[200];
    vector<int> adj[201];
    void dfs(int i ){
        
        for(auto node : adj[i]){
            if(vis[node] == 0){
                vis[node] = 1;
                //cout << node << endl;
                dfs(node);
            }
            
        }
        
    }
    int findCircleNum(vector<vector<int>>& v) {
        int  n= v.size();
        

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(v[i][j] == 1 && i!=j){
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                dfs(i);
                //cout << i << endl;
                cnt++;
            }
        }
        return cnt;
    }
};
