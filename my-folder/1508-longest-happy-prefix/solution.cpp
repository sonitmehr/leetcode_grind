class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();        
        vector<int> pi(n);
        pi[0] = 0;

        int left = 0,i = 1;

        while(i < n){
            if(s[i] == s[left]){
                left ++;
                pi[i] = left; 
                i++;
            }
            else{
                if(left != 0)left = pi[left - 1];
                else {
                    pi[i] = 0;
                    i ++;
                }
            }
        }
        int maxLen = pi[n - 1];
        string ans;
        for(auto &i : s){
            if(maxLen == 0)break;
            maxLen--;
            ans += i;
        }
        return ans;
        



    }
};
