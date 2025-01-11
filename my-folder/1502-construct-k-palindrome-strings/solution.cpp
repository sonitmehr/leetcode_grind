class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;

        for(auto &i : s)mp[i]++;
        int cnt = 0,even = 0;
        for(auto &i : mp){
            // cout << i.first <<  " " << i.second << endl;
            if(i.second % 2 == 1){
                cnt++;
                if(i.second > 1)even+=(i.second -1);
            }
            else even+=i.second;
        }
        return cnt <= k && even + cnt >= k;
    }
};
