class Solution {
public:
    string largestPalindromic(string s) {
        int n = s.size();
        
        map<char,int> m;
        //vector<int> v(n);
        string s1,s2="";
        int middle = -1,zero=0;
        
        for(int i = 0;i<n;i++){
            m[s[i]]++;
            if(s[i] == '0')zero++;
        }
        
        sort(s.rbegin(),s.rend());
        for(int i = 0;i<n;i++){
            if(m[s[i]] >= 2 && zero < n -1){
                int val = m[s[i]] - m[s[i]]%2;
                for(int j=0;j<val/2;j++){
                    s1.push_back(s[i]);
                    m[s[i]]-=2;
                    
                }
                if(m[s[i]]%2)middle = max(middle,s[i]-'0');
            }
            else if(m[s[i]] > 0){
                middle = max(middle,s[i] - '0');
            }
            
            
        }
        s2 = s1;
        reverse(s2.begin(),s2.end());
        if(middle !=-1)s1 += (middle + '0');
        string ans = s1  + s2;
        int start = 0,end = ans.size()-1;
        while(start < end-1 && ans[start]=='0')start++;
        while(end >= 1 && ans[end]=='0')end--;
        ans = ans.substr(start,end - start+1);
        return ans;

        
    }
};
