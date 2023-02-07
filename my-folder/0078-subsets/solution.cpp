class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int> &a,vector<int> &v){
        if(i > a.size())return;
        if(i== a.size()){
           
            ans.push_back(v);
            return;
        }
        
        v.push_back(a[i]);
        f(i+1,a,v);
        v.pop_back();
        f(i + 1,a,v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        f(0,nums,v);
        return ans;
    }
};
