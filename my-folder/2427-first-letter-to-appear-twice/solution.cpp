class Solution {
public:
    char repeatedCharacter(string s) {
        int a[26] = {0};
        
        int n = s.size();
        
        for(int i =0;i<n;i++){
            if(a[s[i] - 'a'])return s[i];
            else a[s[i]-'a']++;
        }
        return -1;
    }
};
