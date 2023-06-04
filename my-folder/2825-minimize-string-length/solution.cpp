class Solution {
public:
    int minimizedStringLength(string s) {
        map<char,int> m;
        for(auto &i : s)m[i] ++;
        return m.size();
    }
};
