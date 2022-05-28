class Solution {
public:
    bool digitCount(string num) {
        string s = num;
        int n = s.size();
        
        int a[10] = {0};
        
        for(int i = 0;i<n;i++){
            a[s[i]-'0']++;
        }
        for(int i = 0;i<n;i++){
            if(a[i] != s[i]-'0')return false;
        }
        
        return true;
    }
};
