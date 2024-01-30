class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        map<int, int> pre_sum;
        int ans=0;
        int cur_sum=0;
        for(int i=0;i<arr.size();i++)
        {
            cur_sum=cur_sum+arr[i];

            if(cur_sum==k)
            {
            ans++;
            }
            if(pre_sum.find(cur_sum-k)!=pre_sum.end())
            {
            ans=ans+pre_sum[cur_sum-k];

            }
            pre_sum[cur_sum]++;
        }
        return ans;
    }
};
