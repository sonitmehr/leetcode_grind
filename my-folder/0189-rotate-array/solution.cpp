class Solution {
public:
    
    void rotateOnce(vector<int>& nums){
        int temp = nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0;i<n;i++){
            ans[(k+i)%n] = nums[i]; 
        }
        for(int i = 0;i<n;i++){
            nums[i] = ans[i];
        }
    }
};
