class Solution {
public:
    
    void f(int i,int n,vector<int> &v,vector<vector<int>> &adj,vector<vector<int>> &ans){
        if(i == n - 1){
            //v.insert(v.begin(),0);
            
            ans.push_back(v);
            return;
        }
        
        for(auto ii : adj[i]){
            v.push_back(ii);
            f(ii,n,v,adj,ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(0);
        int n = graph.size();
        f(0,n,v,graph,ans);
        return ans;
    }
};
