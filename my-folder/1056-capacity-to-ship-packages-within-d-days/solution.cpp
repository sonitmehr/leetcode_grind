class Solution {
public:
    int shipWithinDays(vector<int>& v, int days) {
        int n = v.size();
        int maxi = *max_element(v.begin(),v.end());
        int low = maxi,high = 0;
        for(auto i : v)high += i;

        while(low <= high){
            int mid = (low + high)/2;
            int currSum = 0;
            int d = days;
            for(int i = 0;i < n;i ++){

                if(currSum + v[i] <= mid){
                    currSum += v[i];
                }
                else{
                    currSum = v[i];
                    d--;
                }
            }
            //if(d == 0)return mid;
            if(d > 0)high = mid - 1;
            else low = mid + 1;
        }
        return low;
        
    }
};
