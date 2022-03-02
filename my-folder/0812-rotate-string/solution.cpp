class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string s1 =""; // abcde , n = 5
        
        for(int i = 1;i<n;i++){
            char t = s[0];
            s.erase(0,1);
            s.push_back(t);
            if(s == goal)return true;
        }
        return false;
    }
};
