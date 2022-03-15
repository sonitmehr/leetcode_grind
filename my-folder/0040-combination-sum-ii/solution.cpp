class Solution {
public:
    
    void f(int ind,int n,vector<int> &v,vector<int> &a,vector<vector<int>> &ds,int tar){
        
        if(tar == 0){
            ds.push_back(v);
            return;
        }
        for(int i = ind;i<a.size();i++){
            if(i>ind && a[i]==a[i-1])continue;
            if(a[i]>tar)break;
            v.push_back(a[i]);
            f(i + 1,n,v,a,ds,tar-a[i]);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ds;
        vector<int> v;
        f(0,candidates.size(),v,candidates,ds,target);
        return ds;
    }
};
