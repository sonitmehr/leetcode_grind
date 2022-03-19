class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();
        if(n1 > n2)return false;
        vector<int>a1(26,0);
        vector<int>a2(26,0);
        int l = 0,r= n1-1;
        
        for(int i = 0;i<n1;i++){
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        for(int i = n1;i<=n2;i++){
            if(a1==a2)return true;
            
            if(i!=n2)a2[s2[i]-'a']++;
            a2[s2[l]-'a']--;
            l++;
        }
        return false;
    }
};
