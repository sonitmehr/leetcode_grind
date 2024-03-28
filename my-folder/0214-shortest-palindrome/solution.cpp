class Solution {
public:
    string shortestPalindrome(string s) {
        
        int i = 0,j = 1;
        string temp = s;
        string s_reverse = s;
        reverse(s_reverse.begin(),s_reverse.end());
        s = s + "#" + s_reverse;
        int n = s.size();
        vector<int> lps(n,0);
        while(j < n){
            if(s[i] == s[j]){
                lps[j] = i + 1;
                i ++;
                j ++;
            }
            else{
                if(i == 0){
                    j++;
                }
                else{
                    i = lps[i - 1];
                }
            }
        }
        s = temp;
        int maxi = lps[n - 1];
        string add = s.substr(maxi);

        reverse(add.begin(),add.end());

        return add + s;




    }
};
