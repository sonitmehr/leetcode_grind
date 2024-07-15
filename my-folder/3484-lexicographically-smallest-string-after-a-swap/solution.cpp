class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        int cnt =  1;
        for(int i = 1;i<n;i++){
            int a = s[i - 1]-'0';
            int b = s[i] - '0';
            if(b < a && b%2==a%2 && cnt > 0){
                swap(s[i],s[i-1]);
                cnt--;
            }
        }
        return s;
    }
};
