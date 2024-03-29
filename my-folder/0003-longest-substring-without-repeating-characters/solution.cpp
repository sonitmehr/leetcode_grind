class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;

        int l = 0,r = 0;
        int maxi = 0;
        while(r < n){
            char c = s[r];

            if(st.find(c) != st.end()){
                st.erase(s[l]);
                l++;
            }
            else{
                st.insert(s[r]);
                maxi = max(maxi,(int)st.size());
                r++;
            }
        }
        return maxi;
    }
};
