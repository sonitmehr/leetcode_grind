class Solution {
public:
    int maximumBags(vector<int>& v1, vector<int>& v2, int add) {
        int n = v1.size();
        vector<int>diff(n);
        for(int i = 0;i<n;i++){
            diff[i] = v1[i] - v2[i];
        }
        int cnt = 0;
        sort(diff.begin(),diff.end());
        for(int i= 0;i<n;i++){
            if(diff[i] == 0)cnt++;
            else if(diff[i] > 0 && diff[i] <= add){
                cnt++;
                add-=diff[i];
            }
        }
        return cnt;
    }
};
