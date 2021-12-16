class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return;/*
        if(n==2){
            if(nums[0]==0 && nums[1]!=0){
                swap(nums[0],nums[1]);
            }
        }*/
        else{
            int l=0,r=1;
            while(r<n){
                if(nums[l]==0 && nums[r]==0){
                    r++;
                    
                }else if(nums[l]==0 && nums[r]!=0){
                    swap(nums[l],nums[r]);
                    r++;l++;
                    
                }else{
                    l++;
                    r++;
                }
            }
            
        }
        
    }
};
