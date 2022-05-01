class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int cnt =1;
        string prev = "";
        string s = number;
        int maxi = 0;
        string ans;
        for(int i = 0;i<n;i++){
            if(s[i] == digit){
                ans = max(ans,s.substr(0,i) + s.substr(i+1,n-(i+1)));
            }
        }
        return ans;
    }
};
