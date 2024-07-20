class Solution {
public:

    void solve(int i,vector<int>& v,vector<int> &vec,vector<vector<int>> &ans){
        // if(i == v.size()){
            ans.push_back(vec);
            // return;
        // }


        for(int k = i;k<v.size();k++){
            vec.push_back(v[k]);
            solve(k + 1,v,vec,ans);
            vec.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> vec;

        solve(0,v,vec,ans);
        return ans;
    }
};
