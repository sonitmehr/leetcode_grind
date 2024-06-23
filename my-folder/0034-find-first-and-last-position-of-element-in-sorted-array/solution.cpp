class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0,j = n - 1;
        int low = -1,high = -1;
        
        while(i <= j){
            int mid = (i + j)/2;

            if(nums[mid] == target){
                low = mid;
                j = mid - 1;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        i = 0,j = n -1;
        while(i <= j){
            int mid = (i + j)/2;
            // cout << mid << " " << nums[mid] << endl;
            if(nums[mid] == target){

                high = mid;
                i = mid + 1;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        // if(low == -1)high = -1;
        // else high--;
        return {low,high};
    }
};
