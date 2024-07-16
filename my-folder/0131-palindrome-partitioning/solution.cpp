class Solution {
public:
    vector<vector<string>>ans;

    bool check(string t){
        int i = 0,j = t.size() - 1;

        while(i < j){
            if(t[i] == t[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
     
    void solve(int i,string &s,vector<string> &v){
        if(i == s.size()){
            ans.push_back(v);
            return;
        }

        string t;

        for(int ii = i;ii<s.size();ii++){
            t.push_back(s[ii]);
            if(check(t)){
                // cout << t << endl;
                v.push_back(t);
                solve(ii + 1,s,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0,s,v);
        
       return ans;
    }
};
