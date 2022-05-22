class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        map<char,int> m;
        for(int i = 0;i<n;i++){
            m[s[i]]++;
        }
        if(m.find(letter)==m.end())return 0;
        int percent = (m[letter]*100/n);
        return percent;

    }
};
