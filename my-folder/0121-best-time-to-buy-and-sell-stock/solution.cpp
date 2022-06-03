class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        
        int l = 0,r = 1;
        int maxi = 0;
        while(r < n){
            
            if(prices[l] <= prices[r]){
                maxi = max(maxi,prices[r] - prices[l]);
                r++;
            }
            else{
                l=r;r++;
                
            } 
            
        }
        return maxi;

    }
};
