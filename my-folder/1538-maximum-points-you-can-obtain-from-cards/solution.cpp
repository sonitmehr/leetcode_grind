class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        if(n==1)return v[0];
        int sum = 0;
        
        for(int i = 0;i<k;i++)sum += v[i];
        int ptr = k-1,r = n-1,maxi = sum;
        while(ptr >= 0){
            sum = sum - v[ptr] + v[r];
            maxi = max(sum,maxi);
            ptr--;r--;
        }
        return maxi;
    }
};
