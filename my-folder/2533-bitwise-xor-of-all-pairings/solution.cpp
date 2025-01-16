class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int xori = 0;

        if(n % 2 == 1){
            for(auto &i : nums2)xori = xori ^ i;
        }

        if(m % 2 == 1){
            for(auto &i : nums1)xori = xori ^ i;
        }

        return xori;
    }
};
