class Solution {
public:

   
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1,0);
        pre[0] = 0;
        pre[1] = nums[0];
        for(int i = 0;i<n;i++){
            pre[i + 1] = nums[i];
            pre[i + 1] += pre[i]; 
        }
        // for(auto &i : pre)cout << i << " ";
        map<int,int> m;
        m[0]++;
        int sum = 0,ans = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int check = sum - k;
            if(m[check] > 0){
                ans += m[check];
            }
            
            m[sum]++;
            
        }
        return ans;
        
        return 0;

    }
};
