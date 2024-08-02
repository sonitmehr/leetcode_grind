class Solution {
public:
    int minSwaps(vector<int>& v) {
        int n = v.size();

       int total = 0;
        for(int i = 0;i<n;i++){
            if(v[i] == 1)total++;
        }
        if(total == 0)return 0;

        int ones = 0;
        for(int i = 0;i<total;i++){
            if(v[i] == 1)ones++;
        }

        int cnt = total - ones;
        int ans = cnt;
        int start = 0;
        cout << cnt << " " << ans << endl;
        for(int k = total;k<n + total;k++){
            cout << k << " ";
            ones -= v[start % n];
            ones += v[k % n];
            cout << cnt << " " << ans << endl;
            ans = min(ans,total - ones);
            start ++;
        }

        return ans;


    }
};
