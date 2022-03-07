class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if(n==1)return 1;
        int flag = 0,count=0; // 0 means word not seen yet so dont count spaces.
        int j=n-1;
        
        while(j>=0){
            if(isalpha(s[j])) {
                flag = 1;
                count++;
                
            }
            else if(s[j] == ' ' && flag == 1)break;
            j--;
            
        }
        return count;
    }
};
