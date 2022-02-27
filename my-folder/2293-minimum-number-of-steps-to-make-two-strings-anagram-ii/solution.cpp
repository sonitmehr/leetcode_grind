class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.size(),n2 = t.size();
        vector<int> count(26);
        
        for(auto i : s){
            count[i-'a']++;
        }
        for(auto i : t){
            count[i-'a']--;
            
        }int finale =0;
        for(auto i: count){
            finale+=abs(i);
        }
        return finale;
        
    }
};
