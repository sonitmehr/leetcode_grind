class Solution {
public:
    int n;
    string s;
    
    int f(int i,char prevChar,vector<vector<int>> &dp){
        if(i >= n)return 0;
        int l = 1e9,r = 1e9;
        if(dp[i][prevChar - '0'] != -1)return dp[i][prevChar - '0'];
        if(prevChar == '0'){
            if(s[i] == '0'){
                l = f(i + 1,'0',dp);
                r = f(i + 1,'1',dp) + 1; 

            }else{
                l = f(i+1,'1',dp);
                r = f(i + 1,'0',dp)+1;
            }
        }
        else{
            if(s[i] == '0'){
                l = f(i +1,'1',dp) + 1;

            }
            else{
                l = f(i + 1,'1',dp);
            }
        }
        return dp[i][prevChar - '0'] = min(l,r);

    }

    int minFlipsMonoIncr(string s) {
        this->n = s.size();
        this->s = s;
        vector<vector<int>> dp(s.size() + 1,vector<int>(2,-1));

        return f(0,'0',dp);


    }
};
