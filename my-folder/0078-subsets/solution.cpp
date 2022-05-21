class Solution {
public:
    
    void f(vector<int> &a,int ind,int n,vector<vector<int>> &ans,vector<int> &v){
        if(ind >=n){
            
            ans.push_back(v);
            return;
        }
        v.push_back(a[ind]);
        f(a,ind+1,n,ans,v);
        v.pop_back();
        f(a,ind+1,n,ans,v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        f(nums,0,n,ans,v);
        return ans;
        
    }
};
