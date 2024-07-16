class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &v,vector<int> &a){

        ans.push_back(v);

        for(int ind = i;ind<a.size();ind++){
            if(ind > i && a[ind] == a[ind - 1])continue;
            v.push_back(a[ind]);
            solve(ind + 1,v,a);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(0,v,nums);

        return ans;
    }
};
