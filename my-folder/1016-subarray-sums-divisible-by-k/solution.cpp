class Solution {
public:

    int subarraysDivByK(vector<int>& v, int k) {
        // [4,5,0,-2,-3,1]
       //  [4(1),5(1),0(1),5(2),4(2),1()]
        map<int,int> m;
        int n = v.size();
        m[0]++;
        int ans = 0;
        for(int i = 1;i<n;i++)v[i] += v[i-1];
        for(int i = 0;i<n;i++){
            int md = v[i]%k;
            if(md < 0)md += k;
            ans += m[md];
            m[md]++;
        }
        return ans;
        
    }
};
