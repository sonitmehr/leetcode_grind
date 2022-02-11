class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size(),m_size = ransomNote.size();
        
        unordered_map<int,int> m;
        unordered_map<int,int> m1;
        for(int i = 0;i<n;i++){
            m[magazine[i]]++;
        }
        for(int i = 0;i<m_size;i++){
            m1[ransomNote[i]]++;
        }
        for(int i = 0;i<m_size;i++){
            if(m1[ransomNote[i]] <= m[ransomNote[i]]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
