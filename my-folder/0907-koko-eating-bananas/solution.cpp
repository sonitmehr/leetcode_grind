class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        
        int n = v.size();
        int low = 1,high = *max_element(v.begin(), v.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int temp = h;
            for(int i= 0;i<n;i++){
                int add = v[i]/mid;
                if(v[i] % mid)add++;
                h -= add;
            }
            if (h >= 0){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
            // cout << mid <<  " " << h << endl;
            h = temp;
        }
        return ans;   
    }
};
