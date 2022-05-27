class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2 < n1)return false;
        vector<int> v1(26,0),v2(26,0);
        for(int i = 0;i<n1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int l = 0;
        int r = n1-1;
        while(r<n2){
            if(v1 == v2)return true;
            r++;
            if(r <n2)v2[s2[r]-'a']++;
            v2[s2[l]-'a']--;
            l++;
        }
        return false;
    }
};
