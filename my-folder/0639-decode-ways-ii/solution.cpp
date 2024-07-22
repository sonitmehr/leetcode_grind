class Solution {
public:
int M = 1e9 + 7;
 int solve(int i,string &s,vector<int> &dp){

            if(i >= s.size())return 1;
        
        

        long long ans = 0,mult = 1;
        if(dp[i] != -1)return dp[i];
        if(s[i] == '0')return 0;
        
        if(s[i] == '*'){
            mult = 9;
        }

        ans = (ans + (mult * solve(i + 1,s,dp) % M)) % M;

        if(i + 1 < s.size()){
            char curr = s[i];
            char next = s[i + 1];
            long long total = 0;
            if(curr == '*'){
                if(next == '*')total = 15;
                else{
                    if(next <= '6')total = 2;
                    else total = 1;
                }
            }
            else if(curr <= '2'){
                if(next == '*'){
                    if(curr == '1')total = 9;
                    else total = 6;
                }
                else{
                    string t;
                    t+= curr;
                    t+=next;
                    if(stoi(t) <= 26)total = 1;
                }
            }
            ans = (ans + (total * solve(i + 2,s,dp)) % M) % M;

        }



        return dp[i] = ans;


    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
