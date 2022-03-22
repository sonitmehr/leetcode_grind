class Solution {
public:
    string getSmallestString(int n, int k) {
        int val,vala;
        string s;
        for(int i = n-1;i>=0;i--){
            int val = min(26,k-i);
            s.push_back(val-1 + 'a');
            k = k-val;
        }
        sort(s.begin(),s.end());
        return s;
    }
};
