class Solution {
public:
    int maxJump(vector<int>& v) {
        int maxi = 0;
        int n = v.size();
        for(int i = 0;i<n -2;i+=2){
            int diff = abs(v[i] - v[i + 2]);

            maxi = max(diff,maxi);
        }
        maxi = max(abs(v[n - 1] - v[n - 2]),maxi);
        for(int i = 1;i<n-2;i++){
            int diff = abs(v[i] - v[i + 2]);

            maxi = max(diff,maxi);
        }
        return maxi;
    }
};
