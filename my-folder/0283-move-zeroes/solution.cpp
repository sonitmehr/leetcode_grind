class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return;
        int lastNonZero = 0;
        int lastZero = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
                nums[lastZero] = nums[i];
                lastZero++;
            }
            
        }for(int i = lastZero;i<n;i++){
            nums[i]=0;
        }return;
    }
};
