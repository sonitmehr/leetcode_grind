class Solution {
public:
    vector<int> nums;
    void f(int i,int prev,set<vector<int>> &ans,vector<int> &v){
        if(i >= nums.size()){
            if(v.size() >= 2){
                // for(auto i : v){
                //     i -= 101;
                // }
                ans.insert(v);
                // for(auto i : v){
                //     i += 101;
                // }
            }
            return;
        }
        // for(auto i : v)cout << i << " ";
        // cout << endl;
        if(v.size() >= 2){
            // for(auto i : v){
            //     i -= 101;
            // }
            ans.insert(v);
            // for(auto i : v){
            //     i += 101;
            // }
        }
        //if(i < nums.size() -1 && nums[i] == nums[i+1])
        if(nums[i] >= prev){
            v.push_back(nums[i]);
            f(i + 1,nums[i],ans,v);
            v.pop_back();
        }
        f(i+1,prev,ans,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> v;
        // for(auto i : nums){
        //     i += 101;
        //     cout << i <<  " ";
        // }
        this->nums = nums;
        
        f(0,-1e9,ans,v);
        vector<vector<int>> ans2(ans.begin(),ans.end());
        return ans2;
    }
};
