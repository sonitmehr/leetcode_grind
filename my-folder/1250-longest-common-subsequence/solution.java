class Solution {

    int solve(int i,int j,int dp[][],String s1,String s2){
        
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int one =0;

        if(s1.charAt(i) == s2.charAt(j)){
            one =  1 + solve(i - 1,j - 1,dp,s1,s2); 
        }

        return dp[i][j] = Math.max(one,Math.max(solve(i - 1,j,dp,s1,s2),solve(i,j - 1,dp,s1,s2)));


    }

    public int longestCommonSubsequence(String s1, String s2) {
        int n = s1.length();
        int m = s2.length() ;
        int [][] dp = new int[n + 1][m+ 1];
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dp[i][j] = -1;
            }
        }
        return solve(n - 1,m - 1,dp,s1,s2);
        

    }
}
