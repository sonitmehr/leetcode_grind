class Solution {
public:

    bool solve(int i,vector<int> adj[],int color,vector<int> &arr){
        
        

        

                arr[i] = color;
        for(auto &adjEle : adj[i]){
            if(arr[adjEle] == color){
                return false;
            }
            else if(arr[adjEle] == -1){
                if(solve(adjEle,adj,color ^ 1,arr) == false)return false;
            }
        }
        return true;
        

    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];

        for(int i= 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                adj[i].push_back(graph[i][j]);
            }
        } vector<int> arr(n,-1);
        for(int i = 0;i<n;i++){
            if(arr[i] == -1)
            {
                if(solve(i,adj,0,arr)== false)return false;
            }
        }
        return true;
    //    return solve(0,adj,0,arr);
    }
};
