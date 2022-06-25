class Solution {
public:
    
    void f(int i, vector<int>&a,vector<vector<int>> &ds,vector<int> &v){
        if(i == a.size()){
            ds.push_back(v);
            return;
        }
        v.push_back(a[i]);
        f(i+1,a,ds,v);
        v.pop_back();
        f(i+1,a,ds,v);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> v;
        
        f(0,nums,ds,v);
        return ds;
    }
};
