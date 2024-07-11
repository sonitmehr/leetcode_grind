class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();

        vector<vector<int>> ans;
        for(int i = 0;i<(1 << n);i++){
                vector<int> vec;
            for(int j = 0;j<n;j++){
                int set = (i & (1 << j));
                // cout << set << " "<< i << " " << j << endl;
                if(set){
                    vec.push_back(v[j]);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
