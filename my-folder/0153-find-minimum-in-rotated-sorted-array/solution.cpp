class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int i =0,j = n - 1;
        int ans = INT_MAX;
        while(i <= j){
            int mid = (i + j)/2;
            int curr = v[mid];

            int left = v[i],right = v[j];
            // cout << i << " " << j << " " << mid << " " << v[mid] << endl;
            if(curr >= left){
                ans = min(ans,left);
                i = mid + 1;
            }
            else{
                ans = min(ans,curr);
                j = mid - 1;
            }
        }
        return ans;
        
        }
};
