class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();

        int i = 1,j = n - 2;
        if(n == 1)return 0;
        if(v[0] > v[1])return 0;
        if(v[n - 1] > v[n - 2])return n - 1;
        while(i <= j){
            int mid = (i + j)/2;
            int curr = v[mid];

            int left = INT_MIN,right = INT_MIN;
            if(mid > 0)left = v[mid - 1];
            if(mid < n - 1)right = v[mid + 1];
            // –2147483648
            // Increasing
            if(left < curr && curr > right)return mid;
            else if(left < curr && curr < right){
                i = mid + 1;
            }
            // Decreasing
            else {
                j = mid - 1;
            }
/*
else if((mid == 0 || left < curr) && (curr < right || mid == n - 1)){
                return mid;
            }*/
        }
        return -1;
    }
};
