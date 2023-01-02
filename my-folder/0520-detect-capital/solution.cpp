class Solution {
public:
    bool detectCapitalUse(string word) {
        bool check = true;
        bool capital = false;
        int n = word.size();
        bool first = isupper(word[0]);
        
        if(isupper(word[n-1]))capital =true;
        if(first == false && capital)return false;
        
        for(int i = 1;i<word.size();i++){
            if(capital && isupper(word[i]) == false)return false;
            if(capital == false && isupper(word[i]))return false;
        }
        return true;
    }
};
