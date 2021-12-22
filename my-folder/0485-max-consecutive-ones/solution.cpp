class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(),size = 0,size1 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                size++;
                size1 = max(size1,size);
            }else if(nums[i]!= 1){
                size = 0;
            }            
        }
        return size1;
    }
};
