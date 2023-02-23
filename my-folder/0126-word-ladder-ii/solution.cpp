class Solution {
public:
unordered_map<string,int> m;
vector<vector<string>> ans;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto i : wordList)st.insert(i);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        m[beginWord] = 1;
        st.erase(beginWord); 
        int mini = 1e9;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string currWord = p.first;
            int length = p.second;
            if(currWord == endWord){
                mini =min(mini,length);
                break;
            }
            for(int k = 0;k<currWord.size();k++){
                char ignore = currWord[k];
                char store = currWord[k];
                for(char c = 'a';c <= 'z';c++){
                    if(c != ignore){
                        
                        currWord[k] = c;
                        if(st.find(currWord) != st.end()){
                            m[currWord] = length + 1;
                            q.push({currWord,length + 1});
                            st.erase(currWord);
                        }
                        
                    }
                }
                currWord[k] = store;
            }
            
        }
        //if(mini == 1e9)return 0;
        return mini;
        

    }

    void dfs(string s,vector<string> &v){
        int level = m[s];
        if(level == 1){
            reverse(v.begin(),v.end());
            ans.push_back(v);
            reverse(v.begin(),v.end());
            return;
        }
        for(int i = 0;i<s.size();i++){
            char store = s[i];
            for(char c = 'a';c<='z';c++){
                s[i] = c;
                if(m.find(s) != m.end() && m[s] + 1 == level){
                    v.push_back(s);
                    dfs(s,v);
                    v.pop_back();
                }
            }
            s[i] = store;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int mini= ladderLength(beginWord,endWord,wordList);
        // for(auto i : m){
        //     cout << i.first <<  " " << i.second << endl;
        //  }
        vector<string> v;
        v.push_back(endWord);
        dfs(endWord,v);

        return ans;
    }
};
