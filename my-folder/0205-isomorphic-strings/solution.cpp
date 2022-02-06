class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,char> m;
        unordered_map<char,char> m1;
        
        for(int i = 0;i<s.size();i++){
            if(m.find(s[i]) !=m.end() && m[s[i]]!=t[i]){
                return false;
            }
            if(m1.find(t[i]) !=m1.end() && m1[t[i]]!=s[i]){
                return false;
            }
            m[s[i]] = t[i];
            m1[t[i]] = s[i];
        }
        return true;
        
    }
};
