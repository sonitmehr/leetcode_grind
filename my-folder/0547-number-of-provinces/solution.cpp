class Solution {
public:

    void dfs(int i,vector<int> &visited,vector<vector<int>> &isConnected){
        
        visited[i] = 1;

        for(int j = 0;j<isConnected[i].size(); j++){
            if(isConnected[i][j] == 1 && visited[j] == 0){
                dfs(j,visited,isConnected);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        

        int n = isConnected.size();
        int ans = 0;
        vector<int> visited(n,0);
        for(int i = 1;i<=n;i++){
            if(visited[i - 1] == 0){
                dfs(i - 1,visited,isConnected);
                ans++;
            }
        }
        return ans;
    }
};
/*

[[1,1,0],
 [1,1,0]
 [0,0,1]
*/
