class Solution {
public:
    
    int roman(char c){
        if(c == 'I'){
            return 1;
        }
        else if(c == 'V'){
            return 5;
        }
        else if(c == 'X'){
            return 10;
        }
        else if(c == 'L'){
            return 50;
        }
        else if(c == 'C'){
            return 100;
        }
        else if(c == 'D'){
            return 500;
        }
        else if(c == 'M'){
            return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        int num;
        for (int i = 0;i<s.size();i++)
        {
            if(i == s.size()-1 || roman(s[i])>=roman(s[i+1])){
                num = roman(s[i]);
            }else{
                num = roman(s[i+1]) - roman(s[i]);
                i++;
            }
            sum+=num;
        }
        return sum;
    }
};
