class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        int n=nums1.size(),m=nums2.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            map[nums1[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            if(map.find(nums2[i])!=map.end()&&map[nums2[i]]>0)
                //the second condition here saves the code
            {
                ans.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return ans;
        
        
    }
};
