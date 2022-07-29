class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& s, string p) {
        int n = s.size();
        
        int m = p.size();
        
        map<char,char> m1;
        map<char,char> m2;
        
        vector<string> ans;
        
        for(int i = 0;i<n;i++){
            int flag = 1;
            for(int j = 0;j<m;j++){
                
                if(m1.find(s[i][j]) != m1.end() && m1[s[i][j]] != p[j]){
                    cout << "i " << i<< " j " << j<< endl;
                    cout << "m1[s[i][j]] " << m1[s[i][j]] << " p[j] " << p[j] << endl;
                    flag = 0;
                    break;
                }
                if(m2.find(p[j]) != m2.end() && m2[p[j]] !=s[i][j]){
                    cout << "i " << i<< " j " << j<< endl;
                    cout << "m2[p[j]] " << m2[p[j]] << " s[i][j] " << s[i][j] << endl;
                    flag =0;
                    break;
                }
                
                m1[s[i][j]] = p[j];
                m2[p[j]] = s[i][j];
            }
            if(flag)ans.push_back(s[i]);
            m1.clear();
            m2.clear();
        }
        return ans;
        
    }
};
