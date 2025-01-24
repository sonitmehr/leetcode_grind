class Solution {
public:

    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(auto &node: graph[i]){
                adj[node].push_back(i);
            }
        }
        vector<int> ans;
        vector<int> inDegree(n,0);

        queue<int> q;

        for(int i= 0;i<n;i++){
            for(auto &node : adj[i]){
                inDegree[node]++;
            }
        }
        for(int i = 0;i<n;i++){
            if(inDegree[i] == 0)q.push(i);
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            ans.push_back(p);
            for(auto &node : adj[p]){
                inDegree[node]--;
                if(inDegree[node] == 0){
                    q.push(node);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};
// 6 4 0 1 3 2 5 

