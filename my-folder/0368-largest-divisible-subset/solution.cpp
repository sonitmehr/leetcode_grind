class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+1,1);
        map<int,int>hash;
        sort(v.begin(),v.end());
        int last = 0,maxi = 0;
        for(int i= 0;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev < i;prev++){
                if(v[i]%v[prev] == 0 && dp[i] < (1 + dp[prev])){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        while(hash[last] != last){
            ans.push_back(v[last]);
            last = hash[last];

        }
        ans.push_back(v[last]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
