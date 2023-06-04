class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
         long long m = queries.size();
        
        
        vector<long long> rows(n,0),cols(n,0);
        long long r = 0,c = 0;
        long long ans = 0;
        for(int i = m - 1;i>=0;i--){
            auto q = queries[i];
            int type = q[0],index=q[1],val= q[2];
            
            if(cols[index] == 0 && type == 1){
                c++;
                ans += (n - r)*val;
                cols[index] = 1;
            }
            else if(rows[index] == 0 && type== 0){
                r++;
                ans += (n - c)*val;
                rows[index] = 1;
            }
            
        }return ans;
        
        
    }
};
