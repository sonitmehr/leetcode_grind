class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n = nums.size();
        int a[10001] = {0};
        int maxi = 0;
        
        for(int i =0;i<n;i++){
            a[nums[i]]++;
            maxi = max(maxi,nums[i]);
        }
        for(int i = 0;i <=maxi;i++){
            if(a[i] == 0)return i;
        }
        return maxi + 1;
        
        
    }
    
};
