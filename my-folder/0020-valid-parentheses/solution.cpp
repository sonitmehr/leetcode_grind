class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        static unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        
        for (char x : s) {
            if (m.find(x) != m.end()) {
              st.push(x);  
            } else if (st.size() && m[st.top()] == x) {
                st.pop();
            } else {
                return false;
            }
        }
        
        return st.empty();
    }
};
