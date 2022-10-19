class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int l = 0, r = n - 1,mid;
        while(l <= r){
            mid = l + (r-l)/2;
            int curr = v[mid];
            // Usually we go left here.
            //cout << curr << endl;
            if(curr == target)return mid;
            else if(curr >= v[l]){
                if(curr > target && target >= v[l])r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(target > curr && target <= v[r])l = mid + 1;
                else r = mid - 1;
            }
                
                
        }
        return -1;
    }
};
