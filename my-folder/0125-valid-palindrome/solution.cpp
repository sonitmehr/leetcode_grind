class Solution {
public:
    bool isPalindrome(string s) {
        
               
               
        string correctString = "";
        
        for (char i:s){
            if(isdigit(i) || isalpha(i)){
                correctString.push_back(i);
            }
        }
        transform(correctString.begin(), correctString.end(), correctString.begin(), ::tolower);
        int n = correctString.size();
        int i = 0,j=n-1;  
        while(i<j){
            if(correctString[i] != correctString[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
