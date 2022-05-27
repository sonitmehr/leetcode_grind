class Solution {
public:
    const int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i =0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += nums[j];
                v.push_back(sum);
            }
        }
        //if(right>n)right = right%n;
        //if(left>n)left = left%n;
        sort(v.begin(),v.end());
        int sum1= 0;
        for(int i= left-1;i<=right-1;i++){
            sum1 += v[i];
            sum1 %= M;
        }
        return sum1;
            
    }
};
