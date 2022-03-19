class Solution {
public:
    bool isPalindrome(string s) {
        int n =s.size();
        
        
        string s1 = "";
        
        for(auto i : s){
            if(isalpha(i) || isdigit(i)){
                s1 += tolower(i);
            }
        }
        int n1 = s1.size();
        int i = 0,j = n1-1;
        if(n1 == 0)return true;
        //if(n==1)return true
        while(i<j){
            if(s1[i]!=s1[j])return false;
            i++;j--;
        }
        return true;
    }
};
