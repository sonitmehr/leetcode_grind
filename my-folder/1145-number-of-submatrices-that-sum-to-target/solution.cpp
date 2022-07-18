class Solution {
public:
    
    int f(vector<int>&nums,int k)
    {
         unordered_map<int,int>m;
         int sum=0;
         int ans=0;
         for(int i=0;i<nums.size();++i)
         {
             sum+=nums[i];
             
             if(sum==k)ans++; 
             
             if(m.find(sum-k)!=m.end())ans+=m[sum-k];
             
             m[sum]++;
         }
         return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        int cnt=0;
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<a.size();i++){   
            vector<int> v(m,0);
            for(int ii =i;ii<a.size();ii++){
                
                for(int j=0;j<a[0].size();j++){
                    v[j]+=a[ii][j];
                }
                cnt+=f(v,t);
            }
        }

        return cnt;
    }
};
