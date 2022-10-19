class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();
        int l= 0,r = n-1;
        int mid,curr;
        while(l <=r){
            mid = l + (r-l)/2;
            curr = v[mid];
            if(curr == target)return true;
            if(curr == v[l] && curr == v[r]){
                l++;r--;
            }
            else if(curr >= v[l]){
                if(target >= v[l] && target < curr)r = mid -1;
                else l = mid + 1;
            }
            else{
                if(target <= v[r] && target > curr)l = mid + 1;
                else r = mid - 1;
            }
            
            
        }
        return false;
    }
};
