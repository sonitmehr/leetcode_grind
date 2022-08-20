class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int mini = 1e9,cnt;
        if(k == 1){
            if(s.find("B")!=string::npos)return 0;
            return 1;
        }
        int t = k;
        for(int i = 0;i<n-k + 1;i++){
            cnt = 0;            
            
            for(int j = i;j<i + k;j++){
                if(s[j] == 'W')cnt++;
                
            }
            mini = min(mini,cnt);
            
        }
        
        return mini;
    }
};
