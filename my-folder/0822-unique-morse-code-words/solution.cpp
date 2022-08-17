class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& v) {
        int n = v.size();
        
        string a[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> m;
        
        for(int i = 0;i<n;i++){
            string t;
            for(int j = 0;j<v[i].size();j++){
                t.append(a[v[i][j] - 'a']);
            }
            m.insert(t);
        }
        return m.size();
        
    }
};
