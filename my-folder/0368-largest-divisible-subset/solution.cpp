class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp (n,1);
        vector<int> hash (n,0);
        for(int i= 0;i<n;i++)hash[i] = i;
        sort(nums.begin(),nums.end());
        int ans = 0,last = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] %  nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] =j; 
                }
            }
            if(ans < dp[i]){
                ans = dp[i];
                last = i ;

            }
        }
        cout << last << endl;
        vector<int> vec;

        while(hash[last] != last){
            vec.push_back(nums[last]);
            last = hash[last];
        }
        vec.push_back(nums[last]);
        return vec;
    }
};
