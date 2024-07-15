class Solution {
public:

    void solve(int i,int tar,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        if(i == a.size()){
            
            
            return;
        }
        if(tar == 0){
            ans.push_back(v);
            return;
        }

        if(tar - a[i] >= 0){
            v.push_back(a[i]);
            solve(i,tar-a[i],v,a,ans);
            v.pop_back();
        }
        solve(i +1,tar,v,a,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,target,v,candidates,ans);
        return ans;
    }
};
