class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> sorted;
        for(int i = 0;i<n;i++){
            sorted.push_back({nums[i],i});
        }
        sort(sorted.begin(),sorted.end());
        vector<int> ans(n);
        int start = 0;
        for(int i = 0;i<n;i++){
            if(i == n - 1 || sorted[i + 1].first - sorted[i].first > limit){
                // cout << start << " " << i << endl;
                vector<int> vec; 
                for(int j = start;j<=i;j++){
                    vec.push_back(sorted[j].second);
                }

                sort(vec.begin(),vec.end());

                for(int j = 0;j<vec.size();j++){
                    ans[vec[j]] = sorted[start + j].first;
                }
                start = i + 1;

            }

        }
        return ans;
    }
};
