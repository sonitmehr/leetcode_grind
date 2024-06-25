class Solution {
public:
    int smallestDivisor(vector<int>& v, int t) {
        int n = v.size();
        int low = 1,high = *max_element(v.begin(),v.end());
        while( low <= high){
            int mid = (low + high)/2;

            int val = 0;
            for(int i  =0;i<n;i++){
                val += (v[i]/mid);
                if(v[i] % mid)val++;
            }
            if(val <= t){
                high = mid - 1;
                
            }
            else low = mid + 1;
        }
        return low;

    }
};
