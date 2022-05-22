class Solution {
public:
    void f(vector<int> &ds,vector<int> &a,int ind,int n,int t,vector<vector<int>> &ans){
        if(ind == n){
            if(t == 0){
                ans.push_back(ds);
                
            }
            return;
            
        }
        if(a[ind] <= t){
            ds.push_back(a[ind]);
            f(ds,a,ind,n,t-a[ind],ans);
            ds.pop_back();
            
        }f(ds,a,ind+1,n,t,ans);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        f(ds,candidates,0,n,target,ans);
        return ans;
    }
};
