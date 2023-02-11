class Solution {
public:
    int dp[1001][1001];
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();

        for(int i = 1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                if(s1[i - 1] == s2[j - 1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(int i = 0;i<=n1;i++){
        //     for(int j = 0;j<=n2;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int i = n1,j = n2;
        string ans;
        while(i > 0 && j > 0){
            if(s1[i -1] == s2[j - 1]){
                ans = s1[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans = s1[i-1] + ans;
                i--;
                
            }
            else{
                ans =s2[j - 1] + ans;
                j--;
            }


        }
        while(i > 0){
            ans =s1[i -1] + ans;
            i--;
        }
        while(j > 0){
            ans = s2[j -1 ] + ans;
            j--;
        }
        
        return ans;
    }
};
