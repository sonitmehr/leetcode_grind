class Solution {
public:
    void f(int i,int n,vector<int> &v,vector<vector<int>> &ds,int tar,vector<int> &a){
        if(i == n){
            if(tar == 0) ds.push_back(v);return;
        }
        if(a[i] <= tar){
            v.push_back(a[i]);
            f(i,n,v,ds,tar-a[i],a);
            v.pop_back();
            
        }
        f(i+1,n,v,ds,tar,a);
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> v;
        f(0,candidates.size(),v,ds,target,candidates);
        return ds;
    }
};
