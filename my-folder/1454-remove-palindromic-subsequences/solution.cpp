class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "")return 0;
        int n = s.size();
        vector<int> a(26,0);
        int l =0,r=n-1,flag= 0;
        
        while(l<r){
            if(s[l]!=s[r]){
                flag =1;
            }
            l++;r--;
        }
        int cnt = 0;
        if(flag){
            for(int i = 0;i<n;i++){
                a[s[i]-'a']++;
            }
        
        
            int cnt =0;
            for(int i = 0;i<26;i++){

                if(a[i] > 0) cnt++;
            }
            return cnt;
        }
        return 1;
        
    }
};
