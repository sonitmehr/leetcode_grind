class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0,r = 0;
        set<char> st;
        int maxi = 0;
        while(r < n){
            if(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            else{
                st.insert(s[r]);
                r++;
                maxi = max(maxi,(int)st.size());
            }
        }
        return maxi;
        
    }
};
