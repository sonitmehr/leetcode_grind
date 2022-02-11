class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n_size = s2.size(),m_size = s1.size();
        if(m_size>n_size)return false;
        vector<int> m(26,0);
        vector<int> m1(26,0);
        int l = 0,r=0;
        
        // Takes in size of all indexes in s1
        for(int i = 0;i<m_size;i++){
            m[s1[i] - 'a']++;
            m1[s2[i]-'a']++;
        }
        r = m_size-1;
        while(r<n_size){
            if(m1 == m)return true;
            
            r+=1; // Go to next element.
            
            if(r!=n_size){
                m1[s2[r]-'a']++;
            }
            m1[s2[l]-'a']--;
            l++;
        }
        
        return false;
    }
};
