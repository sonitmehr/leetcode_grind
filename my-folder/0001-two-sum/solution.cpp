class Solution {
public:

  vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        
        // [1,3,1,3,2,3,2] target = 6
        // 1 -> 2
        // 2 -> 6
        // 3 -> 5

        //
        unordered_map<int,int> mp;
//      3,2,4
        for(int i = 0;i<n;i++){
            mp[nums[i]] = i;
        }

        for(int i = 0;i<n;i++){
            int difference = target - nums[i]; // Element to be found

            // Check if that element is in the array
           std::unordered_map<int,int>::iterator it = mp.find(difference);
            
            // If exists then we have the found the answer.
            if (it != mp.end() && mp[difference] != i){
                ans.push_back(i);
                ans.push_back(mp[difference]);
                return ans;
            }


        }
        return ans;

        



        return ans;


    }
};
