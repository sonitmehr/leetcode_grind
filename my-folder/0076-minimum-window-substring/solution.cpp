class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int sz = t.size();
        unordered_map<char,int> m;
        for(auto &c: t)m[c]++;
        int  i = 0,j = 0,cnt = 0,minLen = INT_MAX,startInd = -1;
        while(j < n){
            if(m[s[j]] > 0){
                cnt++;
            }
            m[s[j]]--;
          
            
            while(cnt == sz){
                if(j - i + 1 < minLen){
                    startInd = i;
                    minLen = min(minLen, j - i + 1);
                }
                m[s[i]]++;
                if(m[s[i]] > 0){
                    cnt--;
                }
                i++;
                // cout << startInd << " " << minLen << endl;
            }
            j++;
        }
        if(startInd == -1)return "";
        cout << startInd << " " << minLen << endl;
        // return "";
        return s.substr(startInd,minLen);
    }
};
