class Solution {
public:

    string solve(string &s){
        char prev = s[0];
        int cnt = 0;
        int i = 0,n = s.size();
        string ans;
        while(i < s.size()){
            
            int j = i;
            cnt = 0;
            while(j < n && s[i] == s[j]){
                j++;
                cnt++;
            }
            ans.push_back(cnt + '0');
            ans.push_back(s[i]);

            i = j;
        }
        return ans;
    }


    string countAndSay(int n) {
        string prev = "1";

        for(int i = 2;i<=n;i++){
            prev = solve(prev);
            // cout << prev << endl;
        }
        return prev;
    }
};
