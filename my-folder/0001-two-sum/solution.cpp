#include<vector>
class Solution {
public:
    
    vector < int> twoSum(vector< int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i = 0;i<nums.size();i++){
            int diff = target - nums[i];
            if(m.find(diff) == m.end()){// Did not find
               m[nums[i]] = i; 
            }else{
                v.push_back(i);
                v.push_back(m.find(diff)->second);
            }
        }return v;
    }

        
};
