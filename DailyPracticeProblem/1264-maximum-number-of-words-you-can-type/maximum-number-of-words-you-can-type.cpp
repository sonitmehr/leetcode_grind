class Solution {
public:
    int canBeTypedWords(string text, string br) {
        int ans = 0;
        bool flag = true;
        for(auto &i : text){
            if(i == ' '){
                if(flag)ans++;
                flag = true;
                continue;
            }
            if(flag){
                if(br.find(i) != string::npos){

                    flag = false;
                }
            }
        }
        if(flag){
            ans++;
        }
        return ans;
    }
};