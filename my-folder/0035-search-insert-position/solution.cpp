class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int n = v.size();
        int l=  0,r = n - 1;
        while( l <= r){
            int mid = ( l + r)/2;
            if(v[mid]== target)return mid;
            if(v[mid] < target){
                l = mid + 1;
            }
            else r = mid -1;

        }
        return l;
    }
};
