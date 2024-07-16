class Solution {
public:
    vector<string> ans;
    void solve(int i,unordered_map<char,string> &mp,string &s,string &t){
            if(i == s.size()){
                ans.push_back(t);
                return;
            }
            string letters = mp[s[i]];

            for(int ii= 0;ii<letters.size();ii++){
                t.push_back(letters[ii]);
                solve(i + 1,mp,s,t);
                t.pop_back();
            }
    }

    vector<string> letterCombinations(string s) {
        unordered_map<char,string> mp;
        if(s.size() == 0)return {};
        mp['2'] ="abc";
        mp['3'] ="def";
        mp['4'] ="ghi";
        mp['5'] ="jkl";
        mp['6'] ="mno";
        mp['7'] ="pqrs";
        mp['8'] ="tuv";
        mp['9'] ="wxyz";
        string t;
        solve(0,mp,s,t);
        return ans;
    }
};
