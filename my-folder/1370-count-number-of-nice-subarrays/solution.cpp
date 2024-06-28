class Solution {
public:

    int func(vector<int>& v, int goal){
        if(goal < 0)return 0;
        int n = v.size();
        int l = 0,r = 0;
        int sum = 0,ans = 0;

        while(r < n){

            sum += (v[r] % 2);
            while(sum > goal){
                sum -= (v[l] % 2);
                l++;
            }
            if(sum <= goal){
                ans += r - l + 1;
            }
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& v, int k) {
        return func(v,k) - func(v,k - 1);
    }
};
