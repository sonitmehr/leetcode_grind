class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = s.size(),t1=t.size();
        int i =0;
        int j = 0;
        while(j<t1){
            if(s[i] == t[j])i++;
            
            j++;
        }
        if(i<=s1-1)return false;
        return true;
    }
};
