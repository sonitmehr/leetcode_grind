class Solution {
public:

    int maxCrossingSum(vector<int>& nums,int l,int mid,int r){
        int sum = 0;
        int left_sum = -1e9,right_sum = -1e9;
        for(int i = mid;i>= l;i--){
            sum += nums[i];
            left_sum = max(left_sum,sum);
        }
        sum = 0;
        for(int i = mid;i<=r;i++){
            sum += nums[i];
            right_sum = max(right_sum,sum);
        }
        return max({left_sum,right_sum,left_sum + right_sum - nums[mid]});
    }

    int f(vector<int>&nums,int l,int r){
        if(l > r)return -1e9;
        if(l == r)return nums[l];

        int m = (l + r)/2;

        return max({f(nums,l,m - 1),f(nums,m + 1,r),maxCrossingSum(nums,l,m,r)});

    }



    int maxSubArray(vector<int>& nums) {
        return f(nums,0,nums.size() - 1);
    }
    
};
