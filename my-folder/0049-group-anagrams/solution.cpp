class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        for(int i = 0;i<n;i++){
            string s = strs[i];

            // Generate Hash String by counting frequency of characters
            int freq[26] = {0};
            for(auto &c : s)freq[c-'a']++;
            string hashString;
            for(int it = 0;it<26;it++){
                hashString += to_string(freq[it]);
                hashString += "#";
            }

            mp[hashString].push_back(s);

        }

        vector<vector<string>> anagrams;
        for(auto &i : mp){
            vector<string> anagram = i.second;
            anagrams.push_back(anagram);
        }
        return anagrams;

    }
};
