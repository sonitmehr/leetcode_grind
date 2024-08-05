#define pi pair<int,int>
class Solution {
public:
    
    int solve(vector<int> &queries,vector<int> adj[],int n){
        
        
        queue<pi> q;
        vector<int> dist(n,1e9);
        
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int node = p.first;
            int dis = p.second;
            
            for(auto &adjNode : adj[node]){
                // cout << adjNode << endl;
                if(dist[adjNode] > 1 + dis){
                    dist[adjNode] = 1 + dis;
                    q.push({adjNode,dis + 1});
                }
            }
        }
        
        return dist[n - 1];
        
        
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(int i = 1;i<n;i++){
            adj[i - 1].push_back(i);
        }
//         for(int i = 0;i<n;i++){
//             cout <<"i : " <<  i<<endl;
//             for(auto &j : adj[i]){
//                 cout << j<< " ";
//             }
//             cout << endl;
//         }
        
        vector<int> ans;
        for(auto &q : queries){
            adj[q[0]].push_back(q[1]);
            ans.push_back(solve(q,adj,n));
        }
        return ans;
    }
};
