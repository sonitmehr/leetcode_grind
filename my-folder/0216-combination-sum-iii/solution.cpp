class Solution {
public:
    
    void f(int i,int k,int n,int sum,vector<int> &v,vector<vector<int>> &ans){
        
        if(k == 0){
            if(n == sum){                
                ans.push_back(v);
            }
            return;
        }
        if(i > 9)return ;
        
        v.push_back(i);
        f(i+1,k-1,n,sum + i,v,ans);
        v.pop_back();
        f(i+1,k,n,sum,v,ans);
        
        /*
        else if(i == a.size()){
            return;
        }
        
        
        if(a[i] < n){
            v.push_back(a[i]);
            f(i+1,k-1,n-a[i],a,v,ans);
            v.pop_back();
        }
        f(i+1,k,n,a,v,ans);
        */
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> a = {1,2,3,4,5,6,7,8,9};
        f(1,k,n,0,v,ans);
        return ans;
    }
};
