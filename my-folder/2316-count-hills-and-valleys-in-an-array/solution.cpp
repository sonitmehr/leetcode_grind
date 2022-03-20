class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
       // int left = 0,right=0;
        for(int i = 1;i<n-1;i++){
            if(nums[i] == nums[i-1])continue;
            
            int l = i-1,r = i+1;
            
            while(r < n && nums[i] == nums[r])r++;
            while(l >= 0 && nums[i] == nums[l])l--;
            
            if(r == n || l < 0) continue;
            
            if(nums[i] > nums[l] && nums[i] > nums[r])count++;
            else if(nums[i] < nums[l] && nums[i] < nums[r])count++;
            
            
                
        }
        return count;
        
    }
};
