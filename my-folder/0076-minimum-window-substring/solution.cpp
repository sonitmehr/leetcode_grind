class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        // Make a t_map for elements in t
        for(auto &c : t)tmap[c]++;
    
        int minLength = 1e9,minStart = -1;
        int i=0,j = 0,n=s.size(),counter = t.size();
        
        // Simple 2 pointer sliding window
        while(j < n){
            if(tmap[s[j]] > 0){
                counter--;
            }
            tmap[s[j]]--;
            while(counter == 0){
                
                if(j - i + 1 < minLength){
                    minLength = j - i + 1;
                    minStart = i;
                }
                
                tmap[s[i]]++;
                if(tmap[s[i]] > 0){
                    counter++;
                }
                i++;
            }
            j++;

        }

        return (minLength == 1e9) ? "" : s.substr(minStart,minLength);
    }
};
