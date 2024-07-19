class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt = 0,i = 0,j = 0;
        while(i < n && j < m){
            if(s[j] >= g[i]){
                i++;
                cnt++;
            }
            j++;
        }

        return cnt;
    }
};
