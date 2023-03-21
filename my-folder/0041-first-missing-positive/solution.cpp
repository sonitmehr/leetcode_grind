class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        
        for(int i = 0;i<n;i++){
            int a = nums[i];
            int b;
            while(a > 0 && a <= n){
                if(nums[a - 1] == a)break;
                b = nums[a - 1]; // 1
                nums[a - 1] = a; // 4
                a = b; // 
            }

            // for(auto &i : nums)cout <<i << " ";
            // cout << endl;
        }
        int p = 1;
        int start = 0;
        while(start < n && nums[start] <= 0)start++;
        for(int i = start;i<n;i++){
            if(nums[i] != p)return p;
            p++;
        }
        return p;
        
        
    }
};
