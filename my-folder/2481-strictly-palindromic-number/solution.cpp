class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int t = n;
        
        for(int i = 2;i<=n-2;i++){
            string s;
            
            while(t > 0){
                s += to_string(t%i);
                t/=i;
                
            }
            cout << s << " ";
            string ss = s;
            reverse(ss.begin(),ss.end());
            if(s!=ss)return false;
            t = n;
        }
        return true;
    }
};
