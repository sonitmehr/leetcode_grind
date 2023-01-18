class Solution {
public:
// Refered Editorial, new approach on Kadane's
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
    for (int x : nums) {
        curMax = max(x, curMax + x);  
        
        maxSum = max(maxSum, curMax); 
        curMin = min(x, curMin + x);  
        minSum = min(minSum, curMin); 
        //cout << curMax <<  " " << curMin << " " << minSum << endl;
        totalSum += x;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};
