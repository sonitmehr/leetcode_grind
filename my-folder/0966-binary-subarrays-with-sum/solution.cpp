class Solution {
public:

    int func(vector<int>& v, int goal){
        if(goal < 0)return 0;
        int n = v.size();
        int l = 0,r = 0;
        int ans = 0,sum = 0;
        while(r < n){
            sum += v[r];
            while(sum > goal){
                sum -= v[l];
                l++;
            }
            if(sum <= goal){
                ans += (r - l + 1);
            }
            r++;
            
            
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& v, int goal) {
        return func(v,goal) - func(v,goal - 1);
    }

};
