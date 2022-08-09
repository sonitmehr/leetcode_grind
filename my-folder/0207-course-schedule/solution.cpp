class Solution {
public:
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        int n1 = pre.size();
        vector<vector<int>> adj(n + 3);
        
        vector<int> vis(n + 1,0);
        vector<int> inDeg(n + 1,0);
        //cnt = 0;
        for(int i =0;i<n1;i++){
            
            int a = pre[i][0];
            int b = pre[i][1];
            
            adj[a].push_back(b);
            inDeg[b] ++;
        }
        
        queue<int> q;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(inDeg[i] == 0){
                q.push(i);
                cnt++;
                vis[i] = 1;
            }
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(auto i : adj[curr]){
                if(vis[i] == 0){
                    inDeg[i]--;
                    if(inDeg[i] == 0){
                        cnt++;
                        vis[i] = 1;
                        q.push(i);
                    }
                    
                }
            }
                
            
        }
        
        if(cnt == n)return true;
        return false;
        
        
        
        
    }
};
