class Solution {
public:
    void f(int i,vector<int> &a,vector<vector<int>> &ans,int target,vector<int> &v){
        
        //if(i >= a.size())return;
        if(i == a.size()){
            if(target == 0){
                ans.push_back(v);
                
            }
            return;
        }
        if(a[i] <= target){
            v.push_back(a[i]);
            f(i,a,ans,target - a[i],v);
            v.pop_back();
        }
            f(i+1,a,ans,target,v);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        f(0,nums,ans,target,v);
        
        return ans;
    }
};
