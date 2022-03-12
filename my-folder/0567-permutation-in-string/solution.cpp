class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();
        if(n1>n2)return false;
        int l = 0,r=n1-1;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(int i = 0;i<n1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        while(r<n2){
            if(v1==v2)return true;
            
            r++;
            if(r!=n2)v2[s2[r]-'a']++;
            v2[s2[l]-'a']--;
            
            l++;
        }
        return false;
        
    }
};

/*
s2 = "eidbaooo" m1 = 
s1 = "ab"
r = 2 
l = 0;

*/
