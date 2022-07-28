class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        int n1 = s.size(),n2 = t.size();
        if(n1 != n2)return false;
        for(int i = 0;i<n1;i++){
            m[s[i]]++;
        }
        for(int i = 0;i<n1;i++){
            m[t[i]]--;
            
        }
        
        for(auto i : m){
            if(i.second != 0)return false;
        }
        return true;
    }
};
