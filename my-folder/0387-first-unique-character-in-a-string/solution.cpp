class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        
        int a[26] = {0};
        if(n==1)return 0;
        for(int i = 0;i<n;i++){
            if(a[s[i]-'a'] > 0){
                a[s[i]-'a']=-1;
            }
            if(a[s[i]-'a']!=-1)a[s[i]-'a']++;
        }
        for(int i =0;i<n;i++){
            if(a[s[i]-'a'] == 1)return i;
        }
        return -1;
    }
};
