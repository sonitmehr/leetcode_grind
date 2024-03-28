class Solution {
public:
    void solve(int i,vector<vector<int>> &ans,vector<int> &vec, vector<int> &candidates,int target){
        if(i < 0)return;

        if(target == 0){
            ans.push_back(vec);
            return ;
        }

        if(target - candidates[i] >= 0){
            vec.push_back(candidates[i]);
            solve(i,ans,vec,candidates,target - candidates[i]);
            vec.pop_back();
        }
            solve(i - 1,ans,vec,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = candidates.size();
        solve(n - 1,ans,vec,candidates,target);
        return ans;
    }
};
