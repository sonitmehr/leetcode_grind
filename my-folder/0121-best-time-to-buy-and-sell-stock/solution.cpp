class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost[n];
        int maxi = INT_MIN;
        cost[0] = prices[0];
        for(int i = 1;i<n;i++){
            if(prices[i] - cost[i-1] > 0){
                maxi = max(maxi,prices[i] - cost[i-1]);
                cost[i] = cost[i-1];
            }
            else{
                cost[i] = prices[i]; 
            }
            
        }
        if(maxi == INT_MIN)return 0;
        return maxi;
    }
};
