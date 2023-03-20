class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0,maxi = sum;
        int prev = sum;
        for(auto &i : nums){
            
            
            sum += i;
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi,sum);

        }
        for(auto &i : nums){
            i = -i;
        }
        sum = 0;
        for(auto &i : nums){
            
            
            sum += i;
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi,sum);

        }
        return maxi;
    }
};
