class Solution {
public:

    bool compare (string &s1,string &s2){
        int i = 0,j = 0;
        if(s1.size() != s2.size() + 1)return false;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                i ++ ;
                j ++ ;
            }
            else{
                i ++;
            }
        }
        if(i == s1.size() && j == s2.size())return true;
        return false;

    }

    static bool cmp  (string &s1,string &s2){
           return s1.size() < s2.size();
        }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp (n,1);
        // for(auto &i : words)cout << i << " ";
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(compare(words[i],words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    // cout << i << " " << j << dp[i] << endl;
                 }
            }
            if(ans < dp[i]){
                ans = dp[i];

            }
            // cout << ans << endl;
        }

        return ans;
    }
};
