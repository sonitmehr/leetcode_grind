class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();

        int ans= 0;
        for(int i= 0;i<n;i++){
            char c = s[i];
            if(c == '('){
                st.push(c);
            }
            else{
                
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else st.push(c);
            }
        }
        return st.size();

    }
};
