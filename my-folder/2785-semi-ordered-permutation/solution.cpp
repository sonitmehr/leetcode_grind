class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                for(int j = i;j>=1;j--){
                    count++;
                    swap(nums[j],nums[j - 1]);
                }
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] == n){
                for(int j = i;j<n-1;j++){
                    swap(nums[j],nums[j + 1]);
                    count++;
                }
                break;
            }
        }
        return count;
    }
    
};
