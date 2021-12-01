#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int diff;
        std::vector<int> result;
        unordered_map<int,int> m;
        for (int i = 0;i<n;i++){
            diff = target - nums[i]; // difference
            // check if difference is same as current ele or not
            // if not then proceed.
            if(m.find(diff)  != m.end() && m.find(diff) -> second != i){
                result.push_back(i);
                result.push_back(m.find(diff) -> second);
                return result;
                
            }m[nums[i]] = i; // if doesnt enter if condition, add value to map
        }return result; 
    }
            
        
};
