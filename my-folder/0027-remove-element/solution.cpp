class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastOccuringTwo =0;
        int k=val; 
        int last = lastOccuringTwo;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]!=k){
                nums[last] = nums[i];
                last++;
            }
            
        }return last;
    }
};
