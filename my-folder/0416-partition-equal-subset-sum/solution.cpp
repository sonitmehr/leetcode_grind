class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum +=arr[i];
        }
        if(sum % 2== 1)return false;
        sum/=2;
        vector<int> prev(sum + 1,0);
        vector<int> curr(sum + 1,0);
        prev[0] = 1;
        if(arr[0] <= sum){
            
        prev[arr[0]] = 1;
        }

        for(int i = 1;i<n;i++){
            for(int k = 0;k<=sum;k++){
                bool one = prev[k];
                bool two = false;
                if(k - arr[i] >= 0){
                    two = prev[k - arr[i]];
                }
                curr[k] = one | two;
            }
                prev = curr;
        }
        
        return prev[sum];
    }
};
