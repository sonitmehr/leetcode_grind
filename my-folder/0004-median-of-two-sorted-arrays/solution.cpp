class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size(),m = nums2.size();
        for(int i = 0; i<n;i++){
            v.push_back(nums1[i]);
                                    
        }
        for(int i = 0; i<m;i++){
            v.push_back(nums2[i]);
                                    
        }
        sort(v.begin(),v.end());
        int s = v.size();
        if(s % 2 == 0){
            return (double)(v[(s - 1) / 2] + v[s / 2]) / 2.0;
        }
        return (double)(v[s/2]);
    }
};
