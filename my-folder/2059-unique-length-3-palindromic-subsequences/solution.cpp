class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        map<char,int> mp;
        vector<vector<int>> pre(n,vector<int>(26,0));
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
            }
            int val = s[i] - 'a';
            if(i > 0){

                pre[i] = pre[i - 1];
            }
                pre[i][val] ++;
        }
        int ans =0 ;
        for(int i = n - 1;i>=0 ;i--){
            if(mp.find(s[i]) != mp.end()){
                int l = mp[s[i]];
                int r = i;
                if(r != l){
                    int temp = 0;
                    for(char c = 'a';c<='z';c++){
                        int val = c - 'a';
                        int sub = pre[r - 1][val] - pre[l][val];
                        // cout << "sub : " << c << " " << sub << endl;
                        if(sub > 0)temp++;
                    }
                    // cout << "temp : " << temp << endl;
                // cout << s[i] << " " << l << " " << r << endl; 
                    ans += temp;
                    mp.erase(s[i]);
                }
            }
        }
    return ans;
    }
};
