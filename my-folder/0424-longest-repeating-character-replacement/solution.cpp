class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0, r = 0;
        unordered_map<char,int> m;
        int maxFreq = 0,maxi = 0;
        while(r < n){
            m[s[r]] ++;
            maxFreq = max(maxFreq,m[s[r]]);
            int len = r - l + 1;
            if(len - maxFreq <= k){
                maxi = max(maxi,len);
            }   
            else{
                while(len - maxFreq > k){
                    m[s[l]]--;
                    maxFreq = 0;
                    for(char c = 'A';c<='Z';c++){
                        maxFreq=  max(maxFreq,m[c]);
                    }
                    l++;
                    len = r - l + 1;
                }
                
            } 
            r++;
        
        }
        return maxi;
    }
};
