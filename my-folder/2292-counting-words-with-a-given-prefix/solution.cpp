class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.size(),ans = 0;
        for(auto &w : words){
            if(w.size() < m)continue;
            if(w.substr(0,m) == pref)ans++;
        }
        return ans;
    }
};
