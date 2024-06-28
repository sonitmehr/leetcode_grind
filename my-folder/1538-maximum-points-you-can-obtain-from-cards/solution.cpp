class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int i = 0,j = n -1;
        int ans = 0;
        
        int lsum = 0,rsum = 0;

        for(int i = 0;i<k;i++){
            lsum += v[i];
        }
        int ptr = k - 1;
        ans = lsum;
        for(int i = n - 1;i >= n - k;i--){
            rsum += v[i];
            ans = max(ans,rsum + lsum - v[ptr]);
            lsum -= v[ptr];
            ptr--;
        }

        return ans;
    }
};
