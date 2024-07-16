class Solution {
public:


    vector<vector<int>> ans;

    void solve(int i,vector<int>&v,int n,int k){
        if(n < 0 || k < 0)return;
        if(k == 0 && n == 0){
            ans.push_back(v);
            return;
        }

        for(int ind = i;ind<=9;ind ++){
            v.push_back(ind);
            solve(ind + 1,v,n - ind,k-1);
            v.pop_back();
        }

        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(1,v,n,k);
        return ans;
    }
};
