class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> a(26,0);        
        
        int n = s.size();
        for(int i = 0;i<n;i++){
            a[s[i] - 'a']++;
        }
        // Reattempt tomorrow
        
        sort(a.begin(),a.end());
        
        int cnt = 0;
        
        for (int i = 24; i >= 0; i--) {
            if(a[i] == 0) break;            
            if(a[i] >= a[i+1]){
                int prev = a[i];
                a[i] = max(0, a[i+1] -1);
                cnt += prev - a[i]; 
            }
        }
        return cnt;
    }
};
