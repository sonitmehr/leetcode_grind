class Solution {
public:
    
    bool f(int i1,int i2,int i3,string s1,string s2,string s3,vector<vector<int>> &dp){
        if(i2 >=0 && i1 >=0 && dp[i1][i2]!=-1)return dp[i1][i2];
        if(i1 <0 && i2 <0 && i3< 0){
            return true;
        }
        
        if(i1 >=0  && i2 >=0  && s3[i3] == s2[i2] && s3[i3] == s1[i1])return dp[i1][i2] = f(i1,i2 - 1,i3-1,s1,s2,s3,dp)||f(i1 - 1,i2,i3-1,s1,s2,s3,dp);
        
        else if(i2 >=0  && s3[i3] == s2[i2]) return f(i1,i2-1,i3-1,s1,s2,s3,dp);
        
        else if(i1 >=0  && s3[i3] == s1[i1]) return f(i1-1,i2,i3-1,s1,s2,s3,dp);
        
       
        
        else return false;
        
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
       //memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>dp(n1+1, (vector<int>(n2+1, -1)));
        if(n1 + n2 != s3.size())return false;
        return f(n1-1,n2-1,s3.size()-1,s1,s2,s3,dp);
    }
};
