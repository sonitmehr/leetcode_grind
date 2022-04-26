class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;
        if(n==1)return 1;
        int l = 0;
        int r=0;
        int maxi = 0;
        unordered_set<char> set;
        while(r < n){
            if(set.count(s[r]) == 0){
                set.insert(s[r]);
                r++;
                maxi = max(r-l,maxi);
            }else{
                
                set.clear();
                l++;
                r=l;
            }
        }
        return maxi;
    }
};
            
            
            
        
