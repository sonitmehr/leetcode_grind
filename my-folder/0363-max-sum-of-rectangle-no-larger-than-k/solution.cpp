class Solution {
public:
    // Kadane's algo. Similar leetcode Q done in the past.
    pair<int,pair<int,int>> maxSubArraySum(vector<int> &a, int size)
    {
        int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
  
        for (int i=0; i< size; i++ )
        {
            max_ending_here += a[i];

            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }

            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return {max_so_far,{start,end}};
    }
    int maxSumSubmatrix(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        int maxRight = 0,maxLeft =0,maxDown = 0,maxUp = 0;
        int maxSum = INT_MIN;
        //vector<int> temp(n,0);
        pair<int,pair<int,int>> p;
        int currSum = 0; 
        for(int i= 0;i<m;i++){
            vector<int> temp(n, 0);
            for(int j= i;j<m;j++){
                for(int row =0;row<n;row++){
                    temp[row]+=(v[row][j]);
                }
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : temp) {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                maxSum = std::max(maxSum, curMax);

            }
            //temp.clear();
        }
        //cout << maxLeft << " " << maxRight << " " << maxUp << " " << maxDown << endl;
        return maxSum;
    }
};
