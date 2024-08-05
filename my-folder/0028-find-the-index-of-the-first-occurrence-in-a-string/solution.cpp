class Solution {
public:
vector<int> computeLPS(string &pat){
            
            
            int i = 1;
            int len = 0;
            int n = pat.size();
            vector<int> lps(n,0);
            lps[0] = 0;
            
            while(i < n){
                if(pat[i] == pat[len]){
                    len++;
                    lps[i] = len;
                    // cout << "Entered1" << endl;
                    i++;
                }
                else{
                    // cout << "Entered2" << endl;
                    if(len > 0){
                        len = lps[len - 1];
                    }
                    else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return lps;
        }
    int strStr(string txt, string pat) {
        vector<int> lps = computeLPS(pat);
            int M = pat.size(),N = txt.size();
            int i = 0,j = 0;
            
            while((N - i) >= (M - j)){
                if(pat[j] == txt[i]){
                    
                    j++;
                    i++;
                }
                
                if(j == M){
                    return (i - j);
                    j = lps[j - 1];
                }
                else if(i < N && pat[j] != txt[i]){
                    
                    if(j > 0){
                        j = lps[j - 1];
                    }
                    else{
                        i ++;
                    }
                }
            }
            return -1;
    }
};
