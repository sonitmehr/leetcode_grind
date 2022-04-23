class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0,j=n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            
            int curr = nums[mid];
            if(curr == target)return mid;
            else if(curr >= nums[i]){
                if(curr >= target && target >= nums[i]){
                    j = mid-1;
                }
                else i = mid+1;
            }
            else{
                if(target >= curr && nums[j] >=target){
                    i = mid+1;
                }
                else j = mid-1;
            }
            
        }
        return -1;
    }
};
