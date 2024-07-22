class Solution {
public:

    int solve(int i,string &s,vector<int> &dp){

            if(i >= s.size())return 1;
        
        

        string t;
        int ans = 0;
        if(dp[i] != -1)return dp[i];
        if(s[i] == '0')return 0;
        t.push_back(s[i]);
        cout << t << endl;
        ans += solve(i + 1,s,dp);
        if(i + 1 < s.size() && s[i] == '1' || (i + 1 < s.size() && s[i] == '2' && (s[i + 1] - '0') <= 6) ){
            t.push_back(s[i + 1]);
            cout << "In : ";
            cout << t << endl;
            ans += solve(i + 2,s,dp);
        }
        return dp[i] = ans;


    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
