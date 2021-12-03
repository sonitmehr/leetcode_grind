class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sp[n+2];
        int maxi = INT_MIN;
        sp[0] = prices[0]; 
        
        for(int i = 1;i<n;i++){ 
            if(prices[i]-sp[i-1] > 0){ // profit is prices[i]-sp[i]
                sp[i] = sp[i-1];
                maxi = max(maxi,prices[i]-sp[i-1]);
                
            }else{
                
                sp[i] = prices[i];
            }
        }
        if(maxi == INT_MIN){
            return 0;
        }
        return maxi;
           
    
        
    }
};
