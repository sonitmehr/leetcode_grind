class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int cnt,mini = 1e9;
        
        for(int i= 0;i<=n-k;i++){
            cnt = 0;
            for(int j = i;j<i + k;j++){
                if(s[j] == 'W')cnt++;
            }
            mini = min(cnt,mini);
        }
        return mini;
    }
};
