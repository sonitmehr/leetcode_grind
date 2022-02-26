class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> v;
        unordered_map<int,int>m;
        
        for(int i = 0;i<n1;i++){
            m[nums1[i]]++;
        }
        for(int i = 0;i<n2;i++){
            if(m[nums2[i]]>0){
                v.push_back(nums2[i]);
                m[nums2[i]]=0;
            }
        }
        return v;
    }
};
