class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto i : wordList)st.insert(i);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int mini = 1e9;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string currWord = p.first;
            int length = p.second;
            if(currWord == endWord)mini =min(mini,length);
            for(int k = 0;k<currWord.size();k++){
                char ignore = currWord[k];
                char store = currWord[k];
                for(char c = 'a';c <= 'z';c++){
                    if(c != ignore){
                        
                        currWord[k] = c;
                        if(st.find(currWord) != st.end()){
                            q.push({currWord,length + 1});
                            st.erase(currWord);
                        }
                        
                    }
                }
                currWord[k] = store;
            }
            
        }
        if(mini == 1e9)return 0;
        return mini;
        

    }
};
