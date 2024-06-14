#define pi pair<string,int>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pi> q;
        unordered_set<string> st;
        for(auto &i : wordList)st.insert(i);
        q.push({beginWord,1});
        int mini = 1e9;
        while(!q.empty()){

            auto p = q.front();
            q.pop();

            string currWord = p.first;
            int length = p.second;

            if(currWord == endWord)mini = min(mini,length);

            for(int k = 0;k<currWord.size();k++){
                char ignore = currWord[k];

                for(char c = 'a';c<='z';c++){
                    if(c != ignore){
                        currWord[k] = c;
                        if(st.find(currWord) != st.end()){
                            q.push({currWord,length+1});
                            st.erase(currWord);
                        }
                    }
                    currWord[k] = ignore;
                }
            }

        }
            return mini == 1e9 ? 0 : mini;
        


    }
};
