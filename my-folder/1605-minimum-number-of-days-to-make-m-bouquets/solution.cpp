class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        int low = *min_element(v.begin(), v.end());
        int high = *max_element(v.begin(), v.end());

        int ANSWER = -1;
        long long val = (long long)m*(long long)k;
        if( val > n)return -1;
        while(low <= high){
            int mid = (low + high)/2;

            
            int i = 0,cnt = 0,ans = 0;
            while(i < n){
                if(v[i] <= mid){
                    cnt ++;
                }
                else cnt = 0;
                if(cnt == k){
                    ans++;
                    cnt = 0;
                }
                i++;
            }
            cout << mid << " " << ans << endl;
            if(ans >= m){
                high = mid - 1;
                ANSWER = mid;
            }
            else low = mid + 1;
        }
        // cout << low << endl;
        return low;
    }
};
