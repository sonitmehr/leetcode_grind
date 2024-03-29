class Solution {
public:
    int dp[2001][2001];
    bool solve(int i, int j, string &pattern,string &text){

        if(i < 0 && j < 0)return true;
        if(i < 0 && j >= 0)return false;

        if(i >=0 && j < 0){
            for(int ii = 0;ii<=i;ii++){
                if(pattern[ii] != '*')return false;
            }
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];

        if(pattern[i] == text[j] || pattern[i] == '?')return dp[i][j] = solve(i - 1,j - 1,pattern,text);

        if(pattern[i] == '*'){
            return dp[i][j] = solve(i - 1,j,pattern,text) | solve(i,j - 1,pattern,text);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string text, string pattern) {
        int n = pattern.size(),m = text.size();
        memset(dp,-1,sizeof(dp));
        return solve(n- 1,m-1,pattern,text);
    }
};
