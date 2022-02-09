class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0,temp;
        if(n == 0)return s;
        for(int i= 0;i<n;i++){
            if(s[i] == ' ' || i == n-1){
                int r = (i==n-1)?i:i-1;
                //i = temp;
                while(l<r){
                    swap(s[l],s[r]);
                    l++;r--;
                }
                l = i+1;
            }
        }
        return s;
    }
};
