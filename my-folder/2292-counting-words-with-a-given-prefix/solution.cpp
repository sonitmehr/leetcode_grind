class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(),n1=pref.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(words[i].substr(0,n1) == pref)count++;
            
        }
        return count;
    }
};
