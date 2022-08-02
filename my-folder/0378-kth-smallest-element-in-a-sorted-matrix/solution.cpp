class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        int n = v.size();
        priority_queue <int, vector<int>, greater<int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j < n;j++){
                q.push(v[i][j]);
            }
        }
        k--;
        while(k--)q.pop();
        return q.top();
    }
};
/*
     1  5  9
(k)  0  1  2

    10 11 13
(k)  3  4  5

    12 13 15
(k)  6  7  8

*/
