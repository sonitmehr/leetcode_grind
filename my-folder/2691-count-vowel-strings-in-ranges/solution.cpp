class Solution {
public:

    bool check(string &s){
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int n = s.size();
        if(st.find(s[0]) != st.end() && st.find(s[n - 1]) != st.end())return true;
        return false;


    } 
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n,0);

        
        for(int i = 0;i<n;i++){
            bool p = check(words[i]);
            if(i > 0){
                if(p) pre[i] += pre[i - 1] + 1;
                else pre[i] = pre[i - 1];
            }
            else{
                if(p)pre[i] = 1;
            }
        }
        vector<int> ans;
        for(auto &q : queries){
            int a = q[0];
            int b = q[1];

            int val = pre[b];
            if(a > 0)val -= pre[a - 1];
            ans.push_back(val);
        }

        return ans;
    }
};
