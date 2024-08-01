
#define pi pair<int,string> 
class Solution {
public:
    vector<vector<string>> ans;
    void dfs(string &s,vector<string> &vec, unordered_map<string,int> &mp){
        
        int level = mp[s];

        if(level == 1){
            reverse(vec.begin(),vec.end());

            ans.push_back(vec);
            reverse(vec.begin(),vec.end());
            return;
        }

        for(int i = 0;i<s.size();i++){
            char ignore = s[i];
            for(char c = 'a';c <= 'z';c++){
                if(c != ignore){
                    s[i] = c;
                    cout << s << " " << level << " " << mp[s] + 1 << endl;
                    if(mp.find(s) != mp.end() && mp[s] + 1 == level){
                        cout << "Inside" << endl;
                       vec.push_back(s);
                       dfs(s,vec,mp);
                       vec.pop_back();
                    }
                    s[i] = ignore;
                }
            }
        }


    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,int> mp;
        queue<pi> q;
        q.push({1,beginWord});
        st.erase(beginWord);
        int mini = INT_MAX;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int steps = p.first;
            string word = p.second;

            if(word == endWord){
                cout << steps << endl;
                mini = steps;
                break;
            }

            for(int i = 0;i<word.size();i++){
                char ignore = word[i];
                for(char c = 'a';c <= 'z';c++){
                    if(c != ignore){
                        word[i] = c;
                        if(st.find(word) != st.end()){
                            mp[word] = steps + 1;
                            q.push({steps + 1,word});
                            st.erase(word);
                        }
                    }
                }
                        word[i] = ignore;
            }
        }
        for(auto &i : mp){
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
        vector<string> vec;
        mp[endWord] = mini;
        mp[beginWord] = 1;
        vec.push_back(endWord);
        dfs(endWord,vec,mp);
        return ans;
    }
};
