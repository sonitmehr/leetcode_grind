class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int maxSum = 0;
        
        // Assume last k elements as final answer.
        for(int i = n- k;i<n;i++){
            maxSum += v[i];
        }
        cout << "Maxsum " << maxSum << endl;
        
        int l = 0,r = n - k;
        int newSum = maxSum;
        while(r < n){
            maxSum = maxSum - v[r] + v[l];
            newSum = max(newSum,maxSum);
            l++;r++;
            
        }
        return newSum;
        
    }
};
