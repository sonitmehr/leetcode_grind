class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& v) {
        
        map<string, int> m1;
        int n = v.size();
        int s1 = s.size();
        int n1 = v[0].size(),j;
        vector<int> ans;
        for (int i = 0;i<n;i++) m1[v[i]] ++;
        
        for (int i = 0; i < s1 - n*n1 + 1; i++) {
            map<string,int> m2;
            j = 0;
            while (j < n) {
                string word = s.substr(i + j * n1, n1);
                if (m1[word]>0){
                    m2[word] ++;
                    if (m2[word] > m1[word]) {
                        break;
                    }
                } 
                else break;
                j++;
            }
            if (j == n) {
                ans.push_back(i);
            }
            
        }
        return ans;
        
        
    }
};
