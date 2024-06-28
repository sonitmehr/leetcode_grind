class Solution {
public:
    int fun(vector<int>& v, int k) {
        int n = v.size();

        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> m;
        while (j < n) {
            m[v[j]]++;

            while(m.size() > k){
                m[v[i]]--;
                if(m[v[i]]==0)m.erase(v[i]);
                i++;
            }
            ans += (j - i + 1);

            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k - 1);

    }
};
