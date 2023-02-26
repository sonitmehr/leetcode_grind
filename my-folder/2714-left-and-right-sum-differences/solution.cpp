class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& v) {
        int n = v.size();
        vector<int> left,right;
        left.push_back(0);
        for(int i = 0;i<n-1;i++){
            int prev = left.back();
            left.push_back(v[i]);
            left.back() = left.back() + prev;
        }
        right.push_back(0);
        for(int i = n-1;i>=1;i--){
            int prev = right.back();
            right.push_back(v[i]);
            right.back() = right.back() + prev;
        }
        reverse(right.begin(),right.end());
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = abs(left[i] - right[i]);
        }
        return ans;
    }
};
