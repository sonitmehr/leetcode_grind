class Solution {
public:
    vector<int> adj[100001];
    string label;
    vector<int> dist;
    int ans = 1;
    void dfs(int node){
        dist[node] = 1;
        for(auto child : adj[node]){
            dfs(child);
            if(label[child]!= label[node]){
                ans = max(ans,dist[node] + dist[child]);
                dist[node] = max(dist[node],dist[child] + 1);

                //cout <<node << " " << child << " "<< dist[node] << " " << dist[child] << endl;
            }
        }
        
    }

    int longestPath(vector<int>& parent, string s) {
        for(int i =1;i<parent.size();i++){
            //adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dist.resize(parent.size() + 1);
        label = s;
        dfs(0);
        return ans;
    }
};
