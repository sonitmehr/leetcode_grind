class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int l = 0,r = n - 1;
        int mid;
        while(l <= r){
            
            mid = l + (r-l)/2;
            int curr = nums[mid];
            
            if(nums[l] <= nums[r])return nums[l];
            
            else if(curr >= nums[r]){
                l = mid+1;
            }
            else if(curr < nums[r]){
                r = mid;
            }
            
        }
        // Left pointer should be at the min element.
        return nums[l];
    }
};
