class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int> m;
        if(n == 1)return 1;
        int left = 0,right = 0;
        int maxi = 0;
        
        while(right < n){
            cout << left << " " << right << endl;
            if(m.find(s[right]) != m.end()){
                maxi = max(maxi,right - left);

                left = max(m[s[right]] + 1,left);
                
            }
            m[s[right]] = right;
            right++;
        }
        maxi = max(maxi,right - left);
        return maxi;
    }
};
