class Solution {
public:
    
    bool f(vector<int>&v,int k,int maxi){
        int subArray = 0;
        int n = v.size();
        int currSum = 0;
        
        for(int i = 0;i<n;i++){
            currSum += v[i];
            if(currSum > maxi) currSum = v[i], subArray++;
        }
        subArray++;
        return subArray <= k;
        
        
    }
    
    int splitArray(vector<int>& v, int k) {
        int l = 0,r = 0;
        int n =v.size();
        for(int i= 0;i<n;i++){
            l = max(l,v[i]);
            r += v[i];
        }
        int mid;
        int ans = r;
        while(l<=r){
            mid = l + (r - l)/2;
            if(f(v,k,mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            
        }
        return ans;
        
    }
};
