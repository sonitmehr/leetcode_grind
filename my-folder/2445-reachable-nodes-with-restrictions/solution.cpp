class Solution {
public:
    
    void dfs(int i,vector<int> &vis,vector<vector<int>> &v,int &cnt){
        vis[i] = 1;
        cnt++;
       // cout << "cntout  " << cnt << endl;
        for(auto ii: v[i]){
            if(vis[ii] == 0){
                //cout << "cnt  " << cnt << endl;
                dfs(ii,vis,v,cnt);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& v, vector<int>& r) {
        vector<vector<int>> adj(n+1);
        
        vector<int> vis(n + 1,0);
        for(int i = 0;i<v.size();i++){
            int a = v[i][0];
            int b = v[i][1];
            //cout << "a " << a << "b " << b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        /*for(auto i : adj){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }*/
        for(int i = 0;i<r.size();i++){
            vis[r[i]] = 1;
        }
        int cnt = 0;
        dfs(0,vis,adj,cnt);
        return cnt;
        
    }
};
