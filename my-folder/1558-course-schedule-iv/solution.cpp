
class Solution {
public:

    void topo(int i,int start,vector<int>&vis, unordered_map<int,unordered_set<int>> &mp
,vector<int> adj[]){
        vis[i] = 1;
        for(auto &node : adj[i]){
            if(vis[node] == 0){
                mp[start].insert(node);
                topo(node,start,vis,mp,adj);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        const int n = numCourses;
        vector<int> adj[101];
        vector<bool> ans(queries.size(),false);
        for(auto &i : pre){
            int a = i[0],b = i[1];

            adj[a].push_back(b);
        }
        unordered_map<int,unordered_set<int>> mp;

        for(int i = 0;i<n;i++){
            vector<int> vis(n,0);
            topo(i,i,vis,mp,adj);
        }
        int ind = 0;
        for(auto &q : queries){
            int a = q[0],b = q[1];
            if((mp[a]).find(b) != mp[a].end()){
                ans[ind] = true;
            }
            ind++;
        }
        return ans;
    }
};
