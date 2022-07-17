class Solution {
public:
    int minOperations(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(),n2 = v2.size();
        
        int hcf = v2[0],cnt = 0;
        
        for(int i = 0;i<n2;i++){
            hcf = __gcd(hcf,v2[i]);
        }
        sort(v1.begin(),v1.end());
        for(int i = 0;i<n1;i++){
            if(v1[i] == hcf || hcf%v1[i] == 0)break;
            if(v1[i] < hcf || hcf%v1[i] != 0)cnt++;
        }
        if(cnt == n1)return -1;
        return cnt;
    }
};
