class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<long long> st;
        
        long long two = 1;
        for(int i = 0;i<31;i++){
            st.insert(two);
            two *= 2;
        }
        two = 1;
        for(auto i : nums){
            if(i > *st.begin()){
                int ans =  *(st.begin());
                return ans;
            }
            if(i == *st.begin())st.erase(i);
        }
        //st.erase(*st.begin());
        int ans =  *(st.begin());
        return ans;
        
    }
};
