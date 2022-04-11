class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int i = 0;
        int j = 0;
        while(i<n){
            st.push(pushed[i]);
            i++;
            if(st.top() == popped[j]){
                while(!st.empty() && st.top()==popped[j]){
                    st.pop();
                    
                    j++;
                }
            }
        }
        return st.empty();
    }
};
