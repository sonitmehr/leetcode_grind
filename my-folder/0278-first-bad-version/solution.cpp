// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r  = n,mid;
        if(n == 1)return 1;
        while(l < r){
            mid = l + (r-l)/2;
            
            if(isBadVersion(mid))r = mid;
            else l = mid + 1;
        }
        if(r == l && isBadVersion(l))return l;
        return -1;
    }
};
