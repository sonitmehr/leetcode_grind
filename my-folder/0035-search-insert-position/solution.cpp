class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        int temp;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target) r = mid-1;
            else if(nums[mid] < target) l = mid+1;
            
        }
        
        
        return l;
        
    }
    
};
