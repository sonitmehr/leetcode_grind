class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        set<pair<int,int>> s;
		for(auto num : arr) mp[num]++;                  // find frequency of elements
        for(auto i : mp) s.insert({i.second,i.first});      // sort frequency in descending order
        int deleted =0,ans = 0;
        
        for (auto itr = s.rbegin();itr != s.rend(); itr++){
            deleted += itr->first, ans++;
            if(deleted >= size(arr) / 2) return ans;
        }
      
        

        return -1;  // won't ever be reached
    }
};
