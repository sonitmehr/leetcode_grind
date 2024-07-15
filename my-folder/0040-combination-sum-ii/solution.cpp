class Solution {
public:
    void solve(int i,int tar,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        if(tar < 0)return;
        if(tar == 0){
            ans.push_back(v);
            return;
        }

        for(int ind = i;ind < a.size();ind++){
            if(ind > i && a[ind] == a[ind - 1])continue;
            // if(a[ind] >tar)break;
            v.push_back(a[ind]);
            solve(ind+1,tar - a[ind],v,a,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(0,target,v,candidates,ans);
        return ans;
    }
};
