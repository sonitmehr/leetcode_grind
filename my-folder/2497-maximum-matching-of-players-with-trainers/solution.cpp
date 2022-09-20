class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0,j = 0,cnt=0;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        while(i < n1 && j < n2){
            if(v1[i] <= v2[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};
