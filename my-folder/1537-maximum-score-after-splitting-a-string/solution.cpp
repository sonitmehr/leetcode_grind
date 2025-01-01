class Solution {
public:
    int maxScore(string s) {
        int one = 0,zero = 0;
        
        for(auto &i : s){
            if(i == '0'){

            }
            else one ++;
        }
        int ans = 0,n = s.size();
        for(int i = 0;i<n - 1;i++){
            if(s[i] == '0')zero++;
            else one--;
            ans = max(ans,zero + one);
        }

        return ans;
    }
};
