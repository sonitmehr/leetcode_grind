class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mat(n,vector<int> (n,1e9));

        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for(int via=0;via < n;via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(i == j)mat[i][j] = 0;
                    mat[i][j] = min(mat[i][j],mat[i][via] + mat[via][j]);
                }
            }
	    }
        
        int ans = -1;
        int maxCnt = INT_MAX;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(mat[i][j] <= k)cnt++;
            }
            if(cnt <= maxCnt){
                maxCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
