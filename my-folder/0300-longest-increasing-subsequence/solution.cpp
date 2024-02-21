class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            auto it = lower_bound(temp.begin(), temp.end(), val);
            int ind = it - temp.begin();
            if (ind < temp.size()) {

                temp[ind] = val;
            } else {
                temp.push_back(val);
            }
        }
        return temp.size();
    }
};
