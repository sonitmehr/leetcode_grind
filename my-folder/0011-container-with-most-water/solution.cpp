class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        int maxi = 0;
        while(l < r){
            maxi = max(maxi,min(v[l],v[r])*(r - l));
            if(v[l] <= v[r]){
                l++;
            }
            else r--;
            
        }
        maxi = max(maxi,min(v[l],v[r])*(r - l));
        return maxi;

    }
};
