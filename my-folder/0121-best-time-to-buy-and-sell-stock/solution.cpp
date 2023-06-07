class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int left = v[0],right = v[0];
        int i = 0,j = 1;
        int maxi = 0;
        while(j < n){
            if(v[j] <= v[i]){
                i = j;
            }
            maxi = max(maxi,v[j] - v[i]);
            j++;
        }
        return maxi;
    }
};
