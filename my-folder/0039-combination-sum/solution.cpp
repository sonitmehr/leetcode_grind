class Solution {
public:
    
    void f(int i, int sum,vector<vector<int>> &ans,vector<int> &v,vector<int>&a){
        if(i == a.size()){
            if(sum == 0){
                ans.push_back(v);
                
            }
            return;
        }
        if(sum == 0){
            ans.push_back(v);
            return;
        }
        if(a[i] <= sum){
            v.push_back(a[i]);
            f(i,sum-a[i],ans,v,a);
            v.pop_back();
        }
        f(i+1,sum,ans,v,a);
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        f(0,target,ans,v,a);
        
        return ans;
        
    }
};
