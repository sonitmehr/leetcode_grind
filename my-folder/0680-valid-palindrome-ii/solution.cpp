class Solution {
public:
    
    bool f(string s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                return false;
            
            } 
                
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0,j=n-1;
        int check = 0;
        while(i<j){
            
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                return f(s,i+1,j) || f(s,i,j-1);
            
            }
            
        }
        return true;
    }
};
