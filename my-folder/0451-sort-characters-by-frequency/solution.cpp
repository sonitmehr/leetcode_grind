class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        int maxFreq = -1;
        for (auto& c : s) {
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);
        }
        string ans;

        vector<vector<char>> reverse_map(s.size() + 1);

        for (auto& i : freq) {
            reverse_map[i.second].push_back(i.first);
        }

        for (int i = reverse_map.size() - 1; i >= 1; i--) {
            for (auto& j : reverse_map[i]) {
               for(int k = 0;k<i;k++){ ans += j;}
            }
        }
        return ans;
    }
};
