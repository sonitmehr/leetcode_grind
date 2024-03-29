class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0,right = 0,maxi = 0;

        for(int i= 0;i<n;i++){
            if(left < right){
                left = 0;
                right = 0;
            }
            if(s[i] == '(')left++;
            if(s[i] == ')')right++;

            if(left == right){
                maxi = max(maxi,2*left);
            }
        }
        left = 0,right = 0;
        for(int i= n - 1;i>=0;i--){
            if(left > right){
                left = 0;
                right = 0;
            }
            if(s[i] == '(')left++;
            if(s[i] == ')')right++;

            if(left == right){
                maxi = max(maxi,2*left);
            }
        }
        return maxi;
    }
};
