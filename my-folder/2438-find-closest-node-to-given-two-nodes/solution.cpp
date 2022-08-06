class Solution {
public:
    
    void f(int i,vector<int> &vis,vector<int> &adj,vector<int> &dist,int d){
       // cout << i << " ";
        if(adj[i] == -1){
            dist[i] = d;
            return;
        }
        vis[i] = 1;
        dist[i] = d;
        
        if(vis[adj[i]] == 0)f(adj[i],vis,adj,dist,dist[i] + 1);
        
        
    }
    
    int closestMeetingNode(vector<int>& v, int node1, int node2) {
        
        int n = v.size();
        
        vector<int> vis(n + 1,0);
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        f(node1,vis,v,dist1,0);
        std::fill(vis.begin(), vis.end(), 0);
        //std::fill(myVector.begin(), myVector.end(), 0);
        f(node2,vis,v,dist2,0);
        int mini = 1e9 + 7,ind = -1;
        for(int i = 0;i<n;i++){
            if(dist1[i] == -1 || dist2[i] == -1)continue;
            
            else{
                int t = max(dist1[i],dist2[i]);
                if(t < mini){
                    mini =t;
                    ind = i;
                    
                }
            }
                
            
            
            
        }
        
       /* for(auto i : dist1){
            cout << i << " ";
        }
        cout << endl;
        for(auto i : dist2){
            cout << i << " ";
        }
        cout << endl;*/
        return ind;
    }
};
