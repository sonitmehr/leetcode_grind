class Solution {
public:
    
    void f(vector<int> &v,int target,int& left,int& right,string s){
        int n = v.size();
        int l = 0, r = n - 1,mid,curr;
        while(l <= r){
            mid = l + (-l+r)/2;
            
            curr = v[mid];
            
            if(curr == target){
                
                if(s == "first"){
                    left = mid;
                    r = mid - 1;
                    
                }
                else{
                    right = mid;
                    l = mid + 1;
                }
                
            }          
            
            else if(curr < target)l = mid+1;
            else r= mid-1;
            
            
        }
    }
    
    vector<int> searchRange(vector<int>& v, int target) {
        int n = v.size();
        int left = -1,right =-1;
        //int l = 0, r = n - 1,mid,curr,left = -1,right =-1;
        
        vector<int> ans;
        
        f(v,target,left,right,"first");
        f(v,target,left,right,"second");
        
        ans.push_back(left);
        ans.push_back(right);
        
        return ans;
        
        
    }
};
