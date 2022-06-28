class Solution {
public:
    
    void f(int ind,vector<int> &a,vector<vector<int>> &ds){
        
        if(ind >=a.size()){
            ds.push_back(a);
            return;
        }
        
        for(int i = ind;i<a.size();i++){
            swap(a[i],a[ind]);
            f(ind+1,a,ds);
            swap(a[i],a[ind]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ds;
        //vector<int> v;
        int n = nums.size();
        
        //map<int,bool> m;
        
        
        f(0,nums,ds);
        
        return ds;
    }
};
