class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int maxi = -1;
        for(int i= 0;i<n;i++){
            int num = s[i] - '0';
            maxi = max(num,maxi);
        }
        return maxi;
    }
};
