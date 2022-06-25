class Solution {
public:
    
    void f(int i, vector<int>&a,set<vector<int>> &ds,vector<int> &v){
        if(i == a.size()){
            ds.insert(v);
            return;
        }
        
        v.push_back(a[i]);
        f(i+1,a,ds,v);
        v.pop_back();
        f(i+1,a,ds,v);
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ds1;
        vector<vector<int>> ds;
        vector<int> v;
     
        sort(nums.begin(),nums.end());
        f(0,nums,ds1,v);
        
        for(auto i : ds1){
            ds.push_back(i);
        }
        return ds;
    }
};
