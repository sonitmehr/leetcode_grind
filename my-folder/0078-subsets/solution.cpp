class Solution {
public:

    void solve(int i,vector<int>& v,vector<int> &vec,vector<vector<int>> &ans){
        if(i == v.size()){
            ans.push_back(vec);
            return;
        }


        vec.push_back(v[i]);
        solve(i + 1,v,vec,ans);
        vec.pop_back();
        solve(i + 1,v,vec,ans);

    }

    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> vec;

        solve(0,v,vec,ans);
        return ans;
    }
};
