class Solution {
public:
    string labels;
    vector<int> adj[100001];
    vector<int> ans;
    vector<int> dfs(int node,int parent){
        vector<int> count(26,0);

        for(auto child : adj[node]){
            if(parent!= child){
                vector<int> temp = dfs(child,node);
                for(int i = 0;i<26;i++)count[i] += temp[i];
            }
            
            
        }
        char ch = labels[node];
        count[ch - 'a']++;
        ans[node] = count[ch - 'a'];
        return count;
        
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ans.resize(n);
        this->labels = labels;
        dfs(0,0);
        
        return ans;
    }
};
