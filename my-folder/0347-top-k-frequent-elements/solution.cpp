class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    std::vector<int> ret;
    ret.reserve(nums.size());
    for (auto n : nums) {
      if (1 == ++freq[n]) {
        // Count the frequency for each int, storing each new int as we go
        ret.push_back(n);
      }
    }

    // Piviot around the kth element using custom compare. Elements are not sorted, just
    // reordered such that all elements in the range [0, k] are greater than those in [k + 1, n)
    // This is an (average) O(n) operation
    std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
        return freq[l] > freq[r];
      });
    ret.resize(k);
    return ret;
  }
};
