class Solution {
public:
    
    void f(int i,int sum,vector<vector<int>> &ans,vector<int> &v,vector<int>&a){
        
        if(sum == 0){
            ans.push_back(v);
            return;    
                
        }
            
        for(int ind = i;ind<a.size();ind++){
            if(ind > i && a[ind] == a[ind - 1])continue;
            if(a[ind] >sum)break;
            v.push_back(a[ind]);
            f(ind + 1,sum - a[ind],ans,v,a);
            v.pop_back();
            
                
        }
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        vector<int> v;
        f(0,target,ans,v,a);
        return ans;
    }
};
