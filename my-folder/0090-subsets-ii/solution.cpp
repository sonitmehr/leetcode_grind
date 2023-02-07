class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int>&a,vector<int>&v){
        //if(i > a.size())return;
        
        
        ans.push_back(v);
           
            
        

        for(int ind = i;ind< a.size();ind++){
            if(ind > i && a[ind] == a[ind - 1])continue;
            v.push_back(a[ind]);
            f(ind+1,a,v);
            v.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        f(0,nums,v);
        return ans;
    }
};
