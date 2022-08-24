class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int i = 0,j = 1;
        // buy low sell high
        // i low j high
        //if(n == 1)return v[0];
        int maxi = 0;
        while(j < n){
            
            if(v[i] < v[j]){
                maxi = max(v[j] - v[i],maxi);
                j++;
            }
            else if(v[i] >= v[j]){
                i = j;
                j++;
            }
            
        }
        return maxi;
    }
};
