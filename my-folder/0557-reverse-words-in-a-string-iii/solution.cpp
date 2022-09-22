class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i= 0;
        while(i < n){
            int j;
            
            if(i == 0 || s[i] == ' '){
               j = i+ 1;
                while(j < n && s[j] != ' ')j ++;
                
                j--;
                if(i!=0)i++;
                while(i < j){
                    swap(s[i],s[j]);
                    i++;j--;
                }
                i = j;
            }
            
            i++;
            
            
        }
        return s;
    }
};
