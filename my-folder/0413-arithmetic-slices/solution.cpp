class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <3)return 0;
        int count=0,ans=0;
        for(int i = 0;i<n-2;i++){
            if(nums[i+1] - nums[i] == nums[i+2]-nums[i+1]){
                ans++;
            }
            else{
                count += ans*(ans+1)/2;
                ans=0;
            }
        }
        count += ans*(ans+1)/2;
        return count;
        
    }
    
};
