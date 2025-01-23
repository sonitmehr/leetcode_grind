class Solution {
public:
    int countServers(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            bool isAlone = false;
            for(int j =0;j<m;j++){
                if(mat[i][j] == 1 && vis[i][j] == 0){
                    for(int k = i;k<n;k++){
                        if(mat[k][j] == 1 && vis[k][j] == 0){
                            cnt ++;
                            vis[k][j] = 1; 
                        }
                    }
                }
                else if(mat[i][j] == 1 && vis[i][j] == 1){
                    isAlone = true;
                }
            }
            if(cnt>1){

                ans += cnt;
            }
            else if(isAlone){
                ans += cnt;
            }
        }
        return ans;
    }
};
