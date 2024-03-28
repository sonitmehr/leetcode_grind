class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        string ans = "";

        for(int i = 0;i<n;i++){
            
            int l = i,r = i;
            while(l >= 0 && r < n && s[r] == s[l]){
                
                int len = r - l + 1;
                
                if(len > maxi){
                    // cout << "ENtered top : " << l << " " << r << " " << i << endl; 
                    maxi = len;
                    ans = s.substr(l,len);
                }
                
                
                l --;
                r ++;
            }
            l = i,r = i + 1;
            while(l >= 0 && r < n && s[r] == s[l]){
                
                int len = r - l + 1;
                if(len > maxi){
                    // cout << "ENtered : " << l << " " << r << " " << i << endl; 
                    maxi = len;
                    ans = s.substr(l,len);
                }
                
                
                l --;
                r ++;
            }
            cout << ans << endl;
        }
        return ans;
    }
};
