class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        
        for(int i =0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                if(abs(map.find(nums[i])-> second-i) <= k)return true;
            }
                
            map[nums[i]]=i;
            
        }
        return false;
        
    }
};
