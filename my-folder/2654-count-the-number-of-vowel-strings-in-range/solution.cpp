class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int cnt = 0;
        for(int i= left;i<=right;i++){
            char c = words[i][0],b = words[i].back();
            if(st.count(c)> 0 && st.count(b) > 0){
                cnt++;
            }
        }
        return cnt;
    }
};
