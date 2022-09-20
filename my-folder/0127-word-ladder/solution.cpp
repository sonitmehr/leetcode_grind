class Solution {
public:
    
    int ladderLength(string bW, string eW, vector<string>& v) {
        int n = v.size();
        unordered_set<string> set;
        for(auto i : v)set.insert(i);
        
        queue<pair<string,int>> q;
        
        q.push({bW,1});
        set.erase(bW);
        while(!q.empty()){
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(s == eW)return steps;
            string t;
            for(int i = 0;i<s.size();i++){
                char currLetter = s[i];
                // hit
                for(int j = 0;j<26;j++){
                    s[i] = j + 'a';
                    if(set.find(s)!=set.end()){
                        q.push({s,steps+1});
                        set.erase(s);
                    }                
                }
                s[i] = currLetter; 

            }
            
        }
        return 0;
        
    }
};
