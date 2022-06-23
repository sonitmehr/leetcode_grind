class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        
        int i = 0,j=1;
        int maxi = 0;
        while(j < n){
            if(v[j] < v[i]){
                i = j;
                j++;
            }
            else if(v[i] <= v[j]){
                maxi = max(v[j]-v[i],maxi);
                j++;
            }
        }
        return maxi;
    }
};
