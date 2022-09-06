class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i =0;i<n;i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string t = "";
                while(!st.empty() && st.top() != '['){
                    t = st.top() + t;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()) == true){
                    num = st.top() + num;
                    st.pop();
                }
                int val = stoi(num);
                string finall = "";
                while(val -- ){
                    for(int k = 0;k<t.size();k++){
                        st.push(t[k]);
                    }
                }
            }
            
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};
