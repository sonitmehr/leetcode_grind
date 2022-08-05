class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int a[200] = {0};
        int cnt = 0;
        int n1 = j.size();
        int n2 = s.size();
        
        for(int i = 0;i<n1;i++){
            char c;
            
            
            a[j[i]-'A']++;
        }
        for(int i = 0;i<n2;i++){
            if(a[s[i] - 'A'] > 0)cnt++;
        }
        return cnt;
    }
};
