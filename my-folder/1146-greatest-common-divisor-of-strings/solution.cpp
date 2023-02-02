class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();
        string ans;
        for(int i= 0;i<__gcd(n1,n2);i++){
            if(s1[i] == s2[i])ans += s1[i];
            else break;
            
        }
        int add = ans.size();
        int ptr = 0;
        for(int i =0;i<max(n1,n2);i ++){
            if(n1 >= n2){
                if(s1[i] != ans[ptr])return "";
            }
            else{
                if(s2[i] != ans[ptr])return "";
            }
            ptr = (ptr + 1)%add;
        }ptr = 0;
        for(int i =0;i<min(n1,n2);i ++){
            if(n1 <= n2){
                if(s1[i] != ans[ptr])return "";
            }
            else{
                if(s2[i] != ans[ptr])return "";
            }
            ptr = (ptr + 1)%add;
        }
        return ans;
    }
};
