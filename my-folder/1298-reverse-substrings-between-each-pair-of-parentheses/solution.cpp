#define pi pair<char,int>
class Solution {
public:
    string reverseParentheses(string s) {
        int n =s.size();
        stack<pi> st;
        int lastOpen = -1;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){

                st.push({s[i],i});
            }
            if(s[i] == ')'){
                int last = st.top().second;
                reverse(s.begin() + last + 1,s.begin() + i);
            // cout << last << " ";
            // cout <<i << " " << s << endl;
            st.pop();
            }
        }
        string ans;
        for(int i = 0;i<n;i++){
            if(s[i] !='(' && s[i] != ')'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
