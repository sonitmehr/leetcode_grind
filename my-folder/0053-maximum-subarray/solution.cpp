class Solution {
public:

    int crossingSum(vector<int> &v,int l,int m,int r){
        int left_sum = -1e9;
        int sum = 0;
        for(int i = m;i>=l;i--){
            sum += v[i];
            left_sum = max(sum,left_sum);
        }
        sum = 0;
        int right_sum = -1e9;
        for(int i = m;i<=r;i++){
            sum += v[i];
            right_sum = max(sum,right_sum);
        }
        return max({left_sum,right_sum,left_sum + right_sum - v[m]});
    }

    int f(vector<int> &v,int l,int r){
        if(r < l) return -1e9;
        if(r == l) return v[l];

        int m = (l + r)/2;

        return max({f(v,l,m-1),f(v,m + 1,r),crossingSum(v,l,m,r)});


    }


    int maxSubArray(vector<int>& nums) {
        return f(nums,0,nums.size()-1);
    }
};
