class Solution {
public:
    
    void dfs(int i,vector<vector<int>> &graph,vector<int>&path,vector<vector<int>> &ans){
       


        for(auto node : graph[i]){
            if(node != -1){
                int temp = node;
                path.push_back(node);
                node = -1;
                dfs(temp,graph,path,ans);
                path.pop_back();
            }
        }
         if(i == graph.size()-1)ans.push_back(path);
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        path.push_back(0);
        dfs(0,graph,path,ans);

        return ans;
    }   
};
