class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(),n1 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int num = 0;
        int i =0,j=0;
        while(i<n && j<n1){
            if(s[j] >= g[i]){
                num++;
                i++;j++;
            }else{
                j++;
            }
        }return num;
    }
};
