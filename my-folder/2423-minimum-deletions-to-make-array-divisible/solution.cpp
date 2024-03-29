class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size(),m = numsDivide.size();

        int gcd = numsDivide[0];
        for(int i = 1;i<m;i++){
            gcd = __gcd(gcd,numsDivide[i]);
        }

        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(gcd % nums[i] == 0)return i;
        }
        return -1;
    }
};
