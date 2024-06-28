class Solution {
public:
    int plzhelp(string s, int k) {
    
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int count = 0;

        while (j < s.length()) {
            mp[s[j]]++;

            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            count += (j - i + 1);
            j++;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        // int k = 3;
        unordered_map<char,int> m;
            int n = s.size();
        int count = 0;
        m['a'] = -1;
        m['b'] = -1;
        m['c'] = -1;

        for(int i =0;i<n;i++){
            m[s[i]] = i;

            if(m['a'] != -1 && m['b'] != -1 && m['c'] != -1){
                int mini = min(m['a'],min(m['c'],m['b']));
                count += mini + 1;
            }
        }

        return count;
    }
};
