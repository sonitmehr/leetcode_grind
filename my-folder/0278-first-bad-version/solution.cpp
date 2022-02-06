// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l =0,r = n;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)==true)r = mid;// not mid-1
            else 
            {
               l=mid+1;
            }
            
        }
        if(l==r && isBadVersion(l)){// Returning left. 
            return l;//                Not mid. 
        }
        return -1;
        
    }
};
