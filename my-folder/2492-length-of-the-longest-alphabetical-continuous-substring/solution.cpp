class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        
        int sum = 1,maxi = 1;
        for(int i = 0;i<n-1;i++){
            if(s[i + 1] == s[i] + 1){
                sum ++;
                maxi = max(sum,maxi);
            }
            else sum = 1 ;
            
            
        }
        return maxi;
        
    }
};
