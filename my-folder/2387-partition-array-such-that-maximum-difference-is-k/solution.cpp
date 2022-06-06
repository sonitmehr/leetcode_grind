class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int prev = nums[0],cnt=1;
        for(int i = 0;i<n;i++){
            if(nums[i] - prev > k){
                cnt++;
                prev = nums[i];
            }
        }
        return cnt;
    }
};
