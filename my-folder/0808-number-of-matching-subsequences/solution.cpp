class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int vn = words.size();
        map<string,int> m;
        
        for(int i = 0;i<vn;i++){
            m[words[i]]++;
        }
        int cnt = 0;
        for(auto i : m){
            string t = i.first;
            int n1 = t.size();
            
            int ptr1 = 0,ptr2 = 0;
            
            while(ptr1 < n && ptr2 < n1){
                if(s[ptr1] != t[ptr2]){
                    ptr1++;
                }
                else{
                    ptr1++;
                    ptr2++;
                }
                if(ptr2 == n1){
                    cnt += i.second;
                    //m.erase(words[i]);
                }
            }
        }
        return cnt;
    }
};
