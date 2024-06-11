class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0,sell = 1;
        int ans = 0;
        while(sell < n){
            if(prices[buy] > prices[sell]){
                buy = sell;
                sell ++;
            }
            else{
                ans = max(ans,prices[sell] - prices[buy]);
                sell++;
            }
        }
        return ans;

    }
};
