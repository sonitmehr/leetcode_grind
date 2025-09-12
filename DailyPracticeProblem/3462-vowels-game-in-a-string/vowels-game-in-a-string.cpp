class Solution {
public:
    bool vow(char c){
        if(tolower(c) == 'a')return true;
        if(tolower(c) == 'e')return true;
        if(tolower(c) == 'i')return true;
        if(tolower(c) == 'o')return true;
        if(tolower(c) == 'u')return true;
        return false;
        
        }

    bool doesAliceWin(string s) {
        int cnt =0;
        for(auto &c : s){
            if(vow(c))cnt++;
        }

        if(cnt == 0)return false;
        if(cnt == 1)return true;
        return true;
    }
};