#define pi pair<string,int>
class Solution {
public:

    int ladderLength(string s, string endWord, vector<string>& wordList) {

        int n = s.size();
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<pi> q;
        int ans = 1e9;
        q.push({s,1});
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            string word = p.first;
            int dist = p.second;

            if(word == endWord){
                ans = min(ans,dist);
            }
            for(int i = 0;i<n;i++){
                char t = word[i];
                for(char c = 'a';c<='z';c++){
                    if(c != t){
                        word[i] = c;
                            // cout << word << endl;
                        if(st.find(word) != st.end()){
                            // cout << "Entered" << endl;
                            q.push({word,dist + 1});
                            st.erase(word);
                        }
                        
                    }
                    word[i] = t;
                }
            }
        }
        return ans == 1e9 ? 0 : ans;

    }
};
