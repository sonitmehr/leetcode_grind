class Solution {
public:
int lowerBound(vector<int> &v, int n, int x) {
	int low = 0, high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            // cout << mid << " ";
            if(v[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            // cout << low<< " "<<high << endl;
            
        }
        return ans;
}

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return lowerBound(nums,n,target);
        // int ind = it - nums.begin();
        // return ind;
    }
};
