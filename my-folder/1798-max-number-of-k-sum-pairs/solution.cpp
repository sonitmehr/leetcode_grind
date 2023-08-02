class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        int n = v.size();

        map<int,int> m;
        for(auto &i : v)m[i] ++;
        int ans = 0;
        for(auto &i : m){
            int one = i.first;
            int two = k - one;
            if(m[two] > 0){
                int minus = min(i.second,m[two]);
                if(one == two){
                    minus/=2;
                }
                ans += minus;
                m[one] -= minus;
                m[two] -= minus;
            }
        }
        return ans;
    }
};
