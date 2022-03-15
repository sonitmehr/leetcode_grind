class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string s1 = "";
        int open = 0;
        for(auto i : s){
            if(i == '('){
                open++;
            }
            else if(i == ')'){
                if(open == 0)continue;
                open--;
            }
            s1+=i;
            
        }
        string s2 = "";
        for(int i = s1.size()-1;i>=0;i--){
            if(s1[i] == '(' && open-- > 0)continue;
            s2 += s1[i];
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
};
