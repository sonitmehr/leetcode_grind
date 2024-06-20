class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        double maxi = INT_MIN;
        double pre = 1,suff = 1;
        for(int i = 0;i<n;i++){
            if(pre == 0)pre = 1;
            if(suff == 0)suff = 1;

            pre *= arr[i];
            suff *= arr[n - i - 1];

            maxi = max(maxi,max(pre,suff));
        }

        return (int)maxi;
    }
};
