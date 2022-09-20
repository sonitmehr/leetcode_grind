class Solution {
    unordered_map<string,int> m;
    string b;
    vector<vector<string>> ans;
public:
    
    void dfs(string s,vector<string> &seq){
        if(s == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = m[s];
        for(int i = 0;i<s.size();i++){
            char currLetter = s[i];

            for(int j = 0;j<26;j++){
                s[i] = j + 'a';
                if(m.find(s)!=m.end() && m[s] == steps - 1){
                    seq.push_back(s);
                    dfs(s,seq);
                    seq.pop_back();                    
                }                
            }
            s[i] = currLetter;
        }
        
    }
    
    vector<vector<string>> findLadders(string bW, string eW, vector<string>& v) {
        int n = v.size();
        unordered_set<string> set;
        for(auto i : v)set.insert(i);
        b = bW;
        queue<string> q;
        
        q.push(bW);
        m[bW] = 1;
        
        set.erase(bW);
        while(!q.empty()){
            string s = q.front();
            int steps = m[s];
            q.pop();
            if( s== eW)break;
            
            for(int i = 0;i<s.size();i++){
                char currLetter = s[i];
                
                for(int j = 0;j<26;j++){
                    s[i] = j + 'a';
                    if(set.find(s)!=set.end()){
                        q.push(s);
                        set.erase(s);
                        m[s] = steps + 1;
                    }                
                }
                s[i] = currLetter;
            }
                        
        }
        if(m.find(eW) != m.end()){
            vector<string> sequence;
            sequence.push_back(eW);
            dfs(eW,sequence);            
            
        }
        return ans;
    }
};
