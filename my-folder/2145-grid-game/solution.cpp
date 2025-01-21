class Solution {
public:

  

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> suff(n,vector<long long>(m,0));

        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j = m - 1;j>=0;j--){
                sum += grid[i][j];
                suff[i][j] = sum;
            }
        }
        long long ans = 1e18;
        for(int i= 0;i<m;i++){
            long long top = 0;
            if(i < m - 1)top = suff[0][i + 1];
            long long bot = 0;
            bot = suff[1][0] - suff[1][i];

            long long val = max(top,bot);
            // cout << top << " " << bot << endl;
            ans = min(ans,val);


        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j < m;j ++) {
        //         cout << suff[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
        return 0;

    }
};
