class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        if(n >=1)ans.push_back({1});
        if(n >= 2)ans.push_back({1,1});
        for(int i = 2;i<n;i++){
            vector<int> vec;
            vec.push_back(1);

            for(int j = 0;j<i - 1;j++){
                // cout << ans[i - 1][j] << endl;
                // cout << ans[i - 1][j + 1] << endl;
                // cout << i - 1 << "  " << j << " " << ans.size() << endl;
                vec.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }

            vec.push_back(1);

            ans.push_back(vec);
        }
        return ans;

    }
};
