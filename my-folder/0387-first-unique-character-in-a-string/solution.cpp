class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for(auto &c : s)freq[c-'a']++;
        int i = 0;
        for(auto &c : s){
            int ind = c - 'a';
            if(freq[ind] == 1)return i;
            i++;
            
        }
        return -1;
    }
};
