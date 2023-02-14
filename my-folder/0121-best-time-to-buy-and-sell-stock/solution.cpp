class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int left = v[0],right = v[0];
        int i = 0;
        int maxi = 0;
        while(i < n){
            if(v[i] < left){
                right = v[i];
                left = v[i];
            }
            if(v[i] > right){
                right = v[i];
            }
            maxi=max(maxi,right - left);
            i++;
        }
        return maxi;
    }
};
