class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        set<int> s;
        int cnt=0,maxi = 0;
        for(int i =0;i<n;i++){
            s.insert(nums[i]);        
        }
        for(auto i : s){
            
            int cnt = 1;
            
            for(int k = 1; s.count(i - k)!=0;k++){
                s.erase(i - k);
                cnt++;
            }
            for(int k = 1;s.count(i+k)!=0;k++){
                s.erase(i+k);
                cnt++;
            }
            maxi = max(cnt,maxi);
        }
        return maxi;
    }
};
