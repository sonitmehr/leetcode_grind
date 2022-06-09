class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 =g.size(),n2 = s.size();
        int i =0,j=0,cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i < n1 && j < n2){
            if(s[j] >= g[i]){
                cnt++;
                i++;j++;
            }
            else if(s[j] < g[i]){
                j++;
            }
        }
        return i;
            
    }
};/*
[7,8,9,10]
[7,8,9,10]
*/
