class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1,m2;
        for(auto i : s1)m1[i]++;
        int n = s1.size();
        if(n > s2.size())return false;
        for(int i = 0;i<n;i++){
            m2[s2[i]]++;
        }
        int start = 0;
        if(m1 == m2)return true;
        for(int i = n;i<s2.size();i++){
            m2[s2[start]]--;
            m2[s2[i]]++;
            start++;
            bool flag = true;
            for(char c = 'a';c<='z';c++){
                if(m1[c] != m2[c])flag = false;
            }
            if(flag)return true;
        }
        return false;

    }
};
