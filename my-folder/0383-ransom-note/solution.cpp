class Solution {
public:
    bool canConstruct(string s1, string s2) {
        int a[26]={0};
        int b[26] ={0};
        for(auto i : s2)b[i-'a']++;
        
        for(auto i : s1){
            a[i - 'a']++;
            if(b[i-'a'] < a[i-'a'])return false;
        } 
        return true;
        
    }
};
