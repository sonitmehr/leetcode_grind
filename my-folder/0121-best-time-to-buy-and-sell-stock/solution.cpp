class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cp[n+2];
        cp[0] = prices[0]; // store initial cost of stock on Day 1. 
        
        int maxProfit = INT_MIN;
        
        for(int i = 1;i<n;i++){
            if(prices[i] - cp[i-1] > 0 ){ // IF profit is positive
                cp[i] = cp[i-1];
                maxProfit = max(maxProfit,prices[i] - cp[i-1]);
            }else{
                cp[i] = prices[i];
            }
        }
        if(maxProfit == INT_MIN){
            return 0;
        }
        return maxProfit;
    }
};
